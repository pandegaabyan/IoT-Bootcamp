from machine import Pin, PWM
from utime import sleep_ms

ledPurplePin = Pin(22, Pin.OUT)
ledGreenPin = Pin(21, Pin.OUT)
ledBluePin = Pin(18, Pin.OUT)
ledYellowPin = Pin(16, Pin.OUT)
buzzerPin = Pin(15, Pin.OUT)

toneA = 440
toneB = 494
toneC = 523
toneD = 587
toneE = 659
toneF = 698
toneG = 784

ledPins = [ledPurplePin, ledGreenPin, ledBluePin, ledYellowPin]
tones = [toneA, toneB, toneC, toneD, toneE, toneF, toneG]

buzzer = PWM(buzzerPin)

def play_buzzer_and_sleep(freq, duration_ms, duty_value=512):
    buzzer.freq(freq)
    buzzer.duty(duty_value)
    sleep_ms(duration_ms)
    buzzer.duty(0)
    
def ledPattern1():
    for i in range(4):
        ledPins[i].on()
    play_buzzer_and_sleep(toneG, 500)
    sleep_ms(500)
    
    for i in range(4):
        ledPins[i].off()
    play_buzzer_and_sleep(toneA, 500)
    sleep_ms(500)
    
def ledPattern2():
    for i in range(4):
        ledPins[i].on()
        play_buzzer_and_sleep(tones[i], 500)
        sleep_ms(500)
        ledPins[i].off()
        
def ledPattern3():
    for i in range(4):
        ledPins[i].on()
        play_buzzer_and_sleep(tones[i], 500)
        sleep_ms(500)
    for i in range(3, -1, -1):
        ledPins[i].off()
        play_buzzer_and_sleep(tones[i], 500)
        sleep_ms(500)

while True:
    ledPattern1()
