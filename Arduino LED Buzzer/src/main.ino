#include <Arduino.h>

const int ledPurplePin = 13;
const int ledGreenPin = 10;
const int ledBluePin = 7;
const int ledYellowPin = 4;
const int buzzerPin = 2;

const int toneA = 440;
const int toneB = 494;
const int toneC = 523;
const int toneD = 587;
const int toneE = 659;
const int toneF = 698;
const int toneG = 784;

int ledPins[] = {ledPurplePin, ledGreenPin, ledBluePin, ledYellowPin};
int tones[] = {toneA, toneB, toneC, toneD, toneE, toneF, toneG};

void ledPattern1() {
  tone(buzzerPin, toneG, 500);
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(1000);

  tone(buzzerPin, toneA, 500);
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(1000);
}

void ledPattern2() {
  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, tones[i], 500);
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
}

void ledPattern3() {
  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, tones[i], 500);
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
  }
  for (int i = 3; i >= 0; i--) {
    tone(buzzerPin, tones[i], 500);
    digitalWrite(ledPins[i], LOW);
    delay(1000);
  }
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  ledPattern3();
}