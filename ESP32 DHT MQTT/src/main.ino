#include <WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>

const char* wifiSsid = "Wokwi-GUEST";
const char* wifiPassword = "";
const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883;

const char* temperatureTopic = "ESP32/temperature";
const char* humidityTopic = "ESP32/humidity";
const char* statusTopic = "ESP32/status";
const char* controlTopic = "ESP32/control";

const int ledPin =  22;
const int dhtPin =  13;

const int sensorReadingInterval = 1000;

WiFiClient espClient;
PubSubClient client(espClient);
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

    char statusMessage[5];
    snprintf(statusMessage, 5, "%s", statusString.c_str());
    client.publish(statusTopic, statusMessage);
}

void receivedCallback(char* topic, byte* payload, unsigned int length) {
    Serial.printf("Message received: %s\r\n", topic);
    char statusInput = (char)payload[0];
    Serial.printf("Payload: %c\r\n", statusInput);

    if (statusInput == '0') {
        activeStatus = false;
    } else if (statusInput == '1') {
        activeStatus = true;
    }
    showStatus(activeStatus);
}

void mqttConnect() {
    while (!client.connected()) {
        Serial.print("MQTT connecting ... ");
        char clientId[20];
        sprintf(clientId, "ESP32Client-%ld", random(1000));
        if (client.connect(clientId)) {
            Serial.print("Connected with id: ");
            Serial.println(clientId);
            client.subscribe(controlTopic);
        } else {
            Serial.print("failed, state: ");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
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

    client.setServer(mqttServer, mqttPort);
    client.setCallback(receivedCallback);
}

void loop() {
    if (!client.connected()) {
      mqttConnect();
    }
    client.loop();

    unsigned long currentTime = millis();

    bool shouldMeasure = (currentTime - lastSensorReadingTime) > sensorReadingInterval;
    if (activeStatus && shouldMeasure) {
        lastSensorReadingTime = currentTime;
        float humidity = dhtSensor.readHumidity();
        float temperature = dhtSensor.readTemperature();
		
        Serial.printf("Humidity: %f %%, Temperature: %f C\r\n", humidity, temperature);

        char statusMessage[5];
        snprintf(statusMessage, 5, "%f", humidity);
        client.publish(humidityTopic, statusMessage);
        snprintf(statusMessage, 5, "%f", temperature);
        client.publish(temperatureTopic, statusMessage);
    }
}
