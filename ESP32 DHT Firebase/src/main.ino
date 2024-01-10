#include <WiFi.h>
#include <DHT.h>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

const char* wifiSsid = "Wokwi-GUEST";
const char* wifiPassword = "";
const char* firebaseProjectApiKey = "AIzaSyDSzfTrsef_ZdAEmckQqoJtamQHVB6r8DI";
const char* firebaseDatabaseUrl = "https://esp32-dht-d0967-default-rtdb.asia-southeast1.firebasedatabase.app";

const char* statusPath = "/device/active_status";
const char* controlPath = "/device/active_control";
const char* dhtDataPath = "/dht_data";
const char* timestampKey = "timestamp";
const char* temperatureKey = "temperature";
const char* humidityKey = "humidity";

const int ledPin =  22;
const int dhtPin =  13;

const int sensorReadingInterval = 1000;

DHT dhtSensor(dhtPin, DHT22);
FirebaseData dataMain;
FirebaseData dataStatus;
FirebaseData dataStream;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;

unsigned long lastSensorReadingTime = 0;
bool firebaseSignupOk = false;
bool activeStatus = false;

void showStatus(bool status) {
    String statusString;
    if (status) {
        digitalWrite(ledPin, HIGH);
        statusString = "ON";
    } else {
        digitalWrite(ledPin, LOW);
        statusString = "OFF";
    }
    Serial.printf("Status: %s\r\n", statusString.c_str());

    if (Firebase.ready() && firebaseSignupOk) {
        if (Firebase.RTDB.setBool(&dataStatus, statusPath, status)) {
            Serial.println("Pushing status ok");
        } else {
            Serial.printf("Pushing status error: %s\r\n", dataStatus.errorReason().c_str());
        }
    } else {
        Serial.println("Firebase not ready");
    }
}

void streamCallback(FirebaseStream data) {
    Serial.printf("Stream callback: %s %s %s\r\n", data.streamPath().c_str(), data.dataType().c_str(), data.eventType().c_str());

    if (data.streamPath() == controlPath && data.dataTypeEnum() == firebase_rtdb_data_type_boolean) {
        activeStatus = data.boolData();
        showStatus(activeStatus);
    }
}

void streamTimeoutCallback(bool timeout) {
    if (timeout) {
        Serial.println("Stream timeout, resume automatically ...");
    }
    if (!dataStream.httpConnected()) {
        Serial.printf("error code: %d, reason: %s\r\n", dataStream.httpCode(), dataStream.errorReason().c_str());
    }
}

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    dhtSensor.begin();
    
    Serial.printf("Connecting to %s ", wifiSsid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifiSsid, wifiPassword);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.printf("\r\nWiFi connected, IP address: %s\r\n", WiFi.localIP().toString().c_str());

    Serial.print("Firebase Signup ... ");
    firebaseConfig.api_key = firebaseProjectApiKey;
    firebaseConfig.database_url = firebaseDatabaseUrl;
    if (Firebase.signUp(&firebaseConfig, &firebaseAuth, "", "")) {
        firebaseSignupOk = true;
        Serial.println("ok");
    } else {
        Serial.println(firebaseConfig.signer.signupError.message.c_str());
    }

    /* Assign the callback function for the long running token generation task */
    firebaseConfig.token_status_callback = tokenStatusCallback;
    
    Firebase.begin(&firebaseConfig, &firebaseAuth);
    Firebase.reconnectWiFi(true);

    Serial.print("Firebase Stream ... ");
    dataStream.keepAlive(5, 5, 1);
    if (Firebase.RTDB.beginStream(&dataStream, controlPath)) {
        Serial.println("ok");
    } else {
        Serial.println(dataStream.errorReason());
    }
    Firebase.RTDB.setStreamCallback(&dataStream, streamCallback, streamTimeoutCallback);
}

void loop() {
    unsigned long currentTime = millis();

    bool shouldMeasure = (currentTime - lastSensorReadingTime) > sensorReadingInterval;
    if (activeStatus && shouldMeasure) {
        lastSensorReadingTime = currentTime;
        float humidity = dhtSensor.readHumidity();
        float temperature = dhtSensor.readTemperature();
		
        Serial.printf("Humidity: %f %%, Temperature: %f C\r\n", humidity, temperature);

        if (Firebase.ready() && firebaseSignupOk) {
            FirebaseJson jsonData;
            jsonData.set(humidityKey, humidity);
            jsonData.set(temperatureKey, temperature);
            if (Firebase.RTDB.pushJSON(&dataMain, dhtDataPath, &jsonData)) {
                char fullPath[128];
                char timestampPath[128];
                snprintf(fullPath, sizeof(fullPath), "%s/%s", dataMain.dataPath().c_str(), dataMain.pushName().c_str());
                snprintf(timestampPath, sizeof(fullPath), "%s/%s", fullPath, timestampKey);
                Firebase.RTDB.setTimestamp(&dataMain, timestampPath);
                Serial.printf("Pushing data ok: %s\r\n", fullPath);
            } else {
                Serial.printf("Pushing data error: %s\r\n", dataMain.errorReason().c_str());
            }
        } else {
            Serial.println("Firebase not ready");
        }
    }
}
