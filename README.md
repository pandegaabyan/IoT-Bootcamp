# IoT Bootcamp

Repository ini berisi berbagai project dan materi sebagai bahan ajar dalam IoT Bootcamp.
Bootcamp tersebut diadakan oleh DTETI FT UGM pada Januari 2024 selama beberapa pertemuan.

**Berilah star** jika repository ini terasa menarik atau bermanfaat ⭐

## Timeline

### Day 1

-   Intro to IoT
-   Intro to Arduino & ESP32
-   Basic Programming using Arduino & MicroPython in Wokwi & PlatformIO

**Material**: [IoT Bootcamp - Day 1.pdf](<Materials/IoT Bootcamp - Day 1.pdf>)

**Project**: [Arduino LED Buzzer](#arduino-led-buzzer) & [ESP32 LED Buzzer MicroPython](#esp32-led-buzzer-micropython)

### Day 2

-   Concept of Analog Signal & Button
-   Arduino with Temperature Sensor, Button, and LCD
-   ESP32 with DHT Sensor and WiFi
-   Blynk for Control and Monitoring

**Material**: [IoT Bootcamp - Day 2.pdf](<Materials/IoT Bootcamp - Day 2.pdf>)

**Project**: [Arduino Temperature Button LCD](#arduino-temperature-button-lcd) & [ESP32 DHT Blynk](#esp32-dht-blynk)

### Day 3

-   Concept of MQTT and Implementation in ESP32
-   Concept of Firebase and Implementation in ESP32
-   Introduction to Node-RED

**Material**: [IoT Bootcamp - Day 3.pdf](<Materials/IoT Bootcamp - Day 3.pdf>)

**Project**: [ESP32 DHT MQTT](#esp32-dht-mqtt) & [ESP32 DHT Firebase](#esp32-dht-firebase)

## Project

Semua project menggunakan [Wokwi](https://wokwi.com) untuk desain rangkaian dan simulasi. Karenanya, setiap project memiliki file `wokwi.toml` dan `diagram.json`.

Semua project selain yang berbasis MicroPython menggunakan [PlatformIO](https://platformio.org). Karenanya, project-project tersebut memiliki file `platformio.ini`.

Beberapa project memiliki diagram terkait bagian-bagian dan alur kerja sistem. Itu dapat dilihat di [IoT Bootcamp - DrawIO](https://drive.google.com/file/d/1d4qCNY82LM_rVFt8S4duNpMI8DvbOP35/view?usp=sharing)

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
