# ESP32 LED Buzzer MicroPython

## Description

Program sederhana dalam bahasa MicroPython yang melibatkan empat LED dan sebuah Buzzer.
Terdapat tiga fungsi `ledPattern` yang masing-masing memainkan keempat LED dan Buzzer dengan pola tertentu.
LED dimainkan melalui method `on()` dan `off()` dari `Pin` sementara Buzzer dimainkan melalui fungsi custom `play_buzzer_and_sleep()`. Fungsi untuk Buzzer itu menggunakan `PWM` untuk mengatur frekuensi dan duty value serta `sleep_ms()` untuk mengatur durasi.

## Develop and Run

### Wokwi

[ESP32 LED Buzzer MicroPython](https://wokwi.com/projects/386619885922592769)

### VS Code + PlatformIO + Wokwi

Saat ini belum berhasil running di VS Code, namun VS Code tetap bisa digunakan untuk development.

Tambahkan MicroPython Stubs untuk memperbaiki intellisense dan type checking:

```bash
pip install micropython-esp32-stubs --target typings --no-user
```
