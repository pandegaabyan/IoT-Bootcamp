#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2

const int buttonPin = 2;
const int ledPin =  10;
const int ntcPin = A0;

const unsigned long buttonDebounceDelay = 50;
const int sensorReadingInterval = 1000;
const float sensorBeta = 3950;
const float minTempLimit = 10;
const float maxTempLimit = 40;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

unsigned long lastButtonDebounceTime = 0;
int buttonState = LOW;
int lastButtonReading = LOW;

unsigned long lastSensorReadingTime = 0;
bool activeStatus = false;

bool checkButtonPressed() {
    unsigned long currentTime = millis();
    bool buttonPressed = false;
    int buttonReading = digitalRead(buttonPin);

    if (buttonReading != lastButtonReading) {
        lastButtonDebounceTime = currentTime;
    }

    if ((currentTime - lastButtonDebounceTime) > buttonDebounceDelay) {
        if (buttonReading != buttonState) {
            buttonState = buttonReading;
            if (buttonState == HIGH) {
                buttonPressed = true;
            }
        }
    }

    lastButtonReading = buttonReading;

    return buttonPressed;
}

float getTemperatureInCelcius(int sensorReading) {
    float temperature = 1 / (log(1 / (1023. / sensorReading - 1)) / sensorBeta + 1.0 / 298.15) - 273.15;
    return temperature;
}

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    lcd.init();
}

void loop() {
    unsigned long currentTime = millis();

    if (checkButtonPressed()) {
        activeStatus = !activeStatus;
        if (activeStatus) {
            digitalWrite(ledPin, HIGH);
            lcd.backlight();
            Serial.println("Status: ON");
        } else {
            digitalWrite(ledPin, LOW);
            lcd.noBacklight();
            lcd.clear();
            Serial.println("Status: OFF");
        }
    }

    bool shouldMeasure = (currentTime - lastSensorReadingTime) > sensorReadingInterval;
    if (activeStatus && shouldMeasure) {
        lastSensorReadingTime = currentTime;
        int sensorReading = analogRead(ntcPin);
        float temperature = getTemperatureInCelcius(sensorReading);

        Serial.print("Temp: ");
        Serial.print(temperature);
        Serial.println(" C");

        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Temp: ");
        lcd.print(temperature, 2);
        lcd.print(" C");
        lcd.setCursor(3, 1);
        if (temperature < minTempLimit) {
            lcd.print("Very Cold ");
        } else if (temperature > maxTempLimit) {
            lcd.print(" Very Hot ");
        } else {
            lcd.print("  Normal  ");
        }
    }
}
