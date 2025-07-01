#define BLYNK_TEMPLATE_ID "put-your-template-id"
#define BLYNK_TEMPLATE_NAME "put-your-template-name"
#define BLYNK_AUTH_TOKEN "put-your-auth-token"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>

const char* wifiSsid = "Wokwi-GUEST";
const char* wifiPassword = "";

const int ledPin =  22;
const int dhtPin =  13;

#define controlVpin V0
#define statusVpin V1
#define temperatureVpin V2
#define humidityVpin V3

const int sensorReadingInterval = 1000;

DHT dhtSensor(dhtPin, DHT22);

unsigned long lastSensorReadingTime = 0;
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

    Blynk.virtualWrite(statusVpin, status);
}

BLYNK_CONNECTED() {
    Serial.println("Blynk connected");
    Blynk.syncVirtual(controlVpin);
}

BLYNK_WRITE(controlVpin) {
    Serial.printf("Control pin value: %s\r\n", param);
    int pinValue = param.asInt();
    if (pinValue == 1) {
        activeStatus = true;
    } else {
        activeStatus = false;
    }
    showStatus(activeStatus);
}

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    dhtSensor.begin();

    Blynk.begin(BLYNK_AUTH_TOKEN, wifiSsid, wifiPassword);
    Serial.println("Finish setup");
}

void loop() {
    Blynk.run();

    unsigned long currentTime = millis();

    bool shouldMeasure = (currentTime - lastSensorReadingTime) > sensorReadingInterval;
    if (activeStatus && shouldMeasure) {
        lastSensorReadingTime = currentTime;
        float humidity = dhtSensor.readHumidity();
        float temperature = dhtSensor.readTemperature();
		
        Serial.printf("Humidity: %f %%, Temperature: %f C\r\n", humidity, temperature);

        Blynk.virtualWrite(temperatureVpin, temperature);
        Blynk.virtualWrite(humidityVpin, humidity);
    }
}
