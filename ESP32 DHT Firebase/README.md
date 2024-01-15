# ESP32 DHT Firebase

## Description

Program dalam bahasa Arduino dengan sensor DHT (temperatur dan kelembapan) serta koneksi dengan Firebase untuk mengirimkan hasil pembacaan sensor dan mengatur apakah pengukuran aktif/berjalan atau tidak.

-   Inisiasi dan Koneksi

    -   Pada bagian awal, terdapat pendefinisian konstanta terkait WiFi, Firebase, dan Firebase Paths
    -   Pada bagian awal, terdapat pula pendefinisian tiga `FirebaseData`, perlu tiga agar komunikasi data bisa independen dan tidak saling terblok
    -   Pada `setup()`, terdapat proses koneksi dengan WiFi, Firebase Signup, Firebase Begin, Firebase Begin Stream, dan pengaturan Firebase Stream Callback

-   DHT Sensor

    -   Pada sensor DHT, nilai temperatur dan kelembapan bisa langsung didapatkan dengan `readTemperature()` dan `readHumidity()`

-   Reading and Sending Sensor Data

    -   Pembacaan sensor dan pengiriman hasilnya dilakukan setiap interval tertentu saja sesuai nilai pada `sensorReadingInterval`
    -   Pembacaan sensor dan pengiriman hasilnya hanya dilakukan ketika `activeStatus` bernilai `true`
    -   Variabel `activeStatus` itu diatur melalui `controlPath` dan nilainya terlihat dari LED
    -   Hasil pembacaan sensor diubah ke JSON untuk dikirim ke Firebase
    -   Pengiriman data hanya dilakukan ketika `Firebase.ready()` dan `firebaseSignupOk`
    -   Pengiriman data dilakukan dengan fungsi `Firebase.RTDB.pushJSON()` ke `dhtDataPath` sehingga `dhtDataPath` berisi array of object
    -   Setelah data terkirim, terdapat fungsi `Firebase.RTDB.setTimestamp()` untuk memberi timestamp value ke data yang baru saja terkirim

-   Stream Callback

    -   Pada `setup()`, terdapat inisiasi stream data dari `controlPath`, datanya bertipe `boolean`
    -   Ketika ada perubahan data pada `controlPath`, fungsi `streamCallback()` akan terpanggil
    -   Fungsi `streamCallback()` mengatur nilai `activeStatus` dan memanggil fungsi `showStatus()`
    -   Fungsi `showStatus()` mengatur nyala LED dan mengirimkan data boolean ke `statusPath` sesuai nilai `activeStatus`
    -   Pengiriman data hanya dilakukan ketika `Firebase.ready()` dan `firebaseSignupOk`
    -   Maka dalam hal ini, `controlPath` berisi request sementara `statusPath` berisi response

## Develop and Run

### Wokwi

[ESP32 DHT Firebase](https://wokwi.com/projects/386977281632013313)

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

## Firebase

_to be updated_
