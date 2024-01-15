# ESP32 DHT MQTT

## Description

Program dalam bahasa Arduino dengan sensor DHT (temperatur dan kelembapan) serta koneksi dengan MQTT untuk mengirimkan hasil pembacaan sensor dan mengatur apakah pengukuran aktif/berjalan atau tidak.

-   Inisiasi dan Koneksi

    -   Pada bagian awal, terdapat pendefinisian konstanta terkait WiFi, MQTT, dan MQTT topics
    -   Pada `setup()`, terdapat proses koneksi dengan WiFi dan pengaturan MQTT callback
    -   Pada `loop()`, terdapat proses koneksi dengan MQTT ketika belum terhubung

-   DHT Sensor

    -   Pada sensor DHT, nilai temperatur dan kelembapan bisa langsung didapatkan dengan `readTemperature()` dan `readHumidity()`

-   Reading and Sending Sensor Data

    -   Hasil pembacaan sensor perlu diubah ke float untuk dikirim lewat MQTT
    -   Pembacaan sensor dan pengiriman hasilnya dilakukan setiap interval tertentu saja sesuai nilai pada `sensorReadingInterval`
    -   Pembacaan sensor dan pengiriman hasilnya hanya dilakukan ketika `activeStatus` bernilai `true`
    -   Variabel `activeStatus` itu diatur melalui `controlTopic` dan nilainya terlihat dari LED
    -   Pengiriman data dilakukan ke `temperatureTopic` dan `humidityTopic`

-   MQTT Callback

    -   Proses koneksi dengan MQTT melibatkan subscription ke `controlTopic`
    -   Ketika ada message pada `controlTopic`, fungsi `receivedCallback()` akan terpanggil
    -   Fungsi `receivedCallback()` mengatur nilai `activeStatus` dan memanggil fungsi `showStatus()`
    -   Fungsi `showStatus()` mengatur nyala LED dan mengirimkan message ke `statusTopic` sesuai nilai `activeStatus`
    -   Maka dalam hal ini, `controlTopic` berisi request sementara `statusTopic` berisi response

## Develop and Run

### Wokwi

[ESP32 DHT MQTT](https://wokwi.com/projects/385977328809221121)

Build bisa jadi gagal karena terlalu lama, jauh lebih cepat Build di PlatformIO di lokal.

### VS Code + PlatformIO + Wokwi

-   Pastikan Extensions [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) dan [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) sudah terinstal
-   Clone atau download repository
-   Buka folder project di VS Code, jangan buka keseluruhan folder repository
-   Enjoy Development :)
-   Build project dengan PlatformIO
-   Run dengan Wokwi Simulator
-   Penjelasan lebih ada di file `DEVELOPMENT.md`

## Node-RED

_to be updated_
