# IoT Bootcamp

Repo ini berisi berbagai project dan materi sebagai bahan ajar dalam IoT Bootcamp.
Bootcamp tersebut diadakan oleh DTETI FT UGM pada Januari 2024 selama beberapa pertemuan.

## Project

Semua project menggunakan [Wokwi](https://wokwi.com) untuk desain rangkaian dan simulasi. Karenanya, setiap project memiliki file `wokwi.toml` dan `diagram.json`.

Semua project selain yang berbasis MicroPython menggunakan [PlatformIO](https://platformio.org). Karenanya, project-project tersebut memiliki file `platformio.ini`.

Penjelasan lebih detail untuk setiap project ada di file `README.md` masing-masing. Panduan untuk develop/run project di lokal ada di [DEVELOPMENT.md](DEVELOPMENT.md).

### [Arduino LED Buzzer](<Arduino LED Buzzer>)

Program sederhana dalam bahasa Arduino yang melibatkan beberapa LED dan sebuah Buzzer.

### [ESP32 LED Buzzer MicroPython](<ESP32 LED Buzzer MicroPython>)

Program yang mirip sebelumnya, namun dalam bahasa MicroPython.

### [Arduino Temperature Button LCD](<Arduino Temperature Button LCD>)

Program dalam bahasa Arduino dengan sensor temperatur dan LCD untuk menampilkan hasil pembacaan sensor serta button untuk mengatur apakah pengukuran aktif/berjalan atau tidak.

### [ESP32 DHT Blynk](<ESP32 DHT Blynk>)

Program dalam bahasa Arduino dengan sensor DHT (temperatur dan kelembapan) serta koneksi dengan Blynk untuk mengirimkan hasil pembacaan sensor dan mengatur apakah pengukuran aktif/berjalan atau tidak.

### [ESP32 DHT MQTT](<ESP32 DHT MQTT>)

Program yang mirip sebelumnya, namun koneksi dilakukan melalui MQTT sementara di sisi lain terdapat Node-RED

### [ESP32 DHT Firebase](<ESP32 DHT Firebase>)

Program yang mirip sebelumnya, namun koneksi dilakukan melalui Firebase

## Timeline

### Day 1

-   Intro to IoT
-   Intro to Arduino & ESP32
-   Basic Programming using Arduino & MicroPython in Wokwi & PlatformIO

**Material**: _to be updated_

**Project**: [Arduino LED Buzzer](<Arduino LED Buzzer>) & [ESP32 LED Buzzer MicroPython](<ESP32 LED Buzzer MicroPython>)

### Day 2

-   Concept of Analog Signal & Button
-   Arduino with Temperature Sensor, Button, and LCD
-   ESP32 with DHT Sensor and WiFi
-   Blynk for Control and Monitoring

**Material**: _to be updated_

**Project**: [Arduino Temperature Button LCD](<Arduino Temperature Button LCD>) & [ESP32 DHT Blynk](<ESP32 DHT Blynk>)

### Day 3

-   Concept of MQTT and Implementation in ESP32
-   Concept of Firebase and Implementation in ESP32
-   Introduction to Node-RED

**Material**: _to be updated_

**Project**: [ESP32 DHT MQTT](<ESP32 DHT MQTT>) & [ESP32 DHT Firebase](<ESP32 DHT Firebase>)
