# ESP32 DHT Blynk

## Description

Program dalam bahasa Arduino dengan sensor DHT (temperatur dan kelembapan) serta koneksi dengan Blynk untuk mengirimkan hasil pembacaan sensor dan mengatur apakah pengukuran aktif/berjalan atau tidak.

-   Inisiasi dan Koneksi

    -   Pada bagian paling atas, terdapat beberapa pendefinisian terkait Blynk, ini semua harus di paling atas dan harus menggunakan `define`
    -   Pada bagian awal, terdapat pendefinisian konstanta terkait WiFi
    -   Pada bagian awal, terdapat pula pendefinisian Blynk Virtual Pins, ini juga harus menggunakan `define`
    -   Pada `setup()`, terdapat proses koneksi dengan Blynk melalui WiFi

-   DHT Sensor

    -   Pada sensor DHT, nilai temperatur dan kelembapan bisa langsung didapatkan dengan `readTemperature()` dan `readHumidity()`

-   Reading and Sending Sensor Data

    -   Pembacaan sensor dan pengiriman hasilnya dilakukan setiap interval tertentu saja sesuai nilai pada `sensorReadingInterval`
    -   Pembacaan sensor dan pengiriman hasilnya hanya dilakukan ketika `activeStatus` bernilai `true`
    -   Variabel `activeStatus` itu diatur melalui `controlPath` dan nilainya terlihat dari LED
    -   Hasil pembacaan sensor langsung dikirim dengan `Blynk.virtualWrite()`

-   Blynk Callback

    -   Fungsi `BLYNK_CONNECTED()` merupakan callback yang terpanggil ketika Blynk terkoneksi di awal
    -   Pada fungsi `BLYNK_CONNECTED()`, terdapat `Blynk.syncVirtual(controlVpin)` untuk sinkronisasi state dari IoT device dengan state dari `controlVpin`
    -   Fungsi `BLYNK_WRITE(controlVpin)` juga merupakan callback, namun terpanggil ketika ada perubahan pada `controlVpin`
    -   Pada fungsi `BLYNK_WRITE(controlVpin)`, ada pengaturan nilai `activeStatus` dan pemanggilan fungsi `showStatus()`
    -   Fungsi `showStatus()` mengatur nyala LED dan mengirimkan data ke `statusVpin` sesuai nilai `activeStatus`
    -   Maka dalam hal ini, `controlVpin` berisi request sementara `statusVpin` berisi response

## Develop and Run

### Wokwi

[ESP32 DHT Blynk](https://wokwi.com/projects/386977134213753857)

Build bisa jadi gagal karena terlalu lama, jauh lebih cepat Build di PlatformIO di lokal.

### VS Code + PlatformIO + Wokwi

-   Pastikan Extensions [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) dan [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) sudah terinstal
-   Clone atau download repository
-   Buka folder project di VS Code, jangan buka keseluruhan folder repository
-   Enjoy Development :)
-   Build project dengan PlatformIO
-   Run dengan Wokwi Simulator
-   Penjelasan lebih ada di file `DEVELOPMENT.md`

## Blynk

_to be updated_
