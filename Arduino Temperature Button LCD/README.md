# Arduino Temperature Button LCD

## Description

Program dalam bahasa Arduino dengan sensor temperatur dan LCD untuk menampilkan hasil pembacaan sensor serta button untuk mengatur apakah pengukuran aktif/berjalan atau tidak.

-   Temperature Sensor

    -   Sensor nya adalah sensor NTC yang analog sehingga dibaca melalui `analogRead()`
    -   Hasil pembacaan itu perlu diolah sebagaimana pada fungsi `getTemperatureInCelcius()` lalu ditampilkan ke LCD

-   LCD

    -   LCD nya menggunakan input I2C sehingga perlu dihubungkan dengan pin I2C pada Arduino, yaitu `A4` dan `A5`.

-   Reading Sensor

    -   Sensor akan dibaca setiap interval tertentu saja sesuai nilai pada `sensorReadingInterval`
    -   Sensor akan dibaca dan LCD akan menyala hanya ketika `activeStatus` bernilai `true`
    -   Variabel `activeStatus` itu diatur melalui Button dan nilainya terlihat dari LED

-   Button

    -   State dari Button dibaca dengan `digitalRead()` dan melibatkan mekanisme "debouncing" sebagaimana pada fungsi `checkButtonPressed()`

## Develop and Run

### Wokwi

[Arduino Temperature Button LCD](https://wokwi.com/projects/386168445311095809)

### VS Code + PlatformIO + Wokwi

-   Pastikan Extensions [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) dan [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) sudah terinstal
-   Clone atau download repository
-   Buka folder project di VS Code, jangan buka keseluruhan folder repository
-   Enjoy Development :)
-   Build project dengan PlatformIO
-   Run dengan Wokwi Simulator
-   Penjelasan lebih ada di file `DEVELOPMENT.md`
