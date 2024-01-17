# Development Preparation and Tips

Ini merupakan panduan untuk develop/run project di lokal. Development utamanya dilakukan di VS Code sementara running simulasi dilakukan dengan Wokwi.

## VS Code and Main Extensions

### VS Code

#### Install

[Visual Studio Code](https://code.visualstudio.com/Download)

#### Description

Visual Studio Code (VS Code) adalah IDE populer dengan berbagai fitur dan Extensions. VS Code digunakan untuk development semua project di sini.

#### Extensions

Explore Extensions di VS Code dengan klik icon Extensions di Activity Bar (paling kiri) atau "Ctrl+Shift+X". Cari dan pilih yang dibutuhkan, lalu klik "Install".

### PlatformIO IDE - VS Code Extension

#### Install

[PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

#### Description

PlatformIO memiliki berbagai fitur untuk memudahkan development project IoT: managing project, managing library, debugging, uploading, dan banyak lagi.

#### Accessing

-   Klik icon PlatformIO di Activity Bar (paling kiri)
-   Terlihat berbagai fungsionalitas di Primary Side Bar (kiri), ada "Project Tasks" (kiri atas) dan "Quick Access" (kiri bawah)

#### Project Management

-   Buka "Quick Access" > "PIO Home" > "Projects & Configuration" lewat Primary Side Bar (kiri)
-   "Create New Project" untuk membuat project baru
-   Pilih Board sesuai dengan yang digunakan, misalnya "Arduino Uno" atau "DOIT ESP32 DEVKIT V1"
-   Pilih Framework yang diinginkan, umumnya "Arduino"
-   Uncheck "Use default location" untuk memilih lokasi folder project secara manual
-   Klik "Finish"
-   Project Configuration tersimpan di file `platformio.ini`, bisa diedit langsung tapi sebaiknya diedit lewat "PIO Home"

#### Library Management

-   Buka "Quick Access" > "PIO Home" > "Libraries" lewat Primary Side Bar (kiri)
-   Cari library yang dibutuhkan, misalnya "LiquidCrystal_I2C"
-   Buka, klik "Add to Project", pilih project yang butuh library itu, lalu klik "Add"
-   Library suatu project juga tersimpan di file `platformio.ini`, bisa diedit langsung tapi sebaiknya diedit lewat "PIO Home"

#### Build Project

-   Sebelum dijalankan, project perlu di-build dulu, kecuali untuk project MicroPython
-   Klik "Project Tasks" > "Build" lewat Primary Side Bar (kiri)
-   Hasil build tersimpan di `.pio/build`
-   Pada "Project Tasks", terlihat pula fungsionalitas seperti "Upload", "Monitor", dan lainnya

### Wokwi Simulator - VS Code Extension

#### Install

[Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)

#### Description

Wokwi Simulator digunakan untuk menghubungkan VS Code dengan Wokwi sehingga development bisa di VS Code sementara simulasinya di Wokwi.

#### Wokwi TOML File

-   Perlu ada file `wokwi.toml` berisi konfigurasi untuk menjalankan simulasi di Wokwi
-   Contoh `wokwi.toml` untuk board "Arduino Uno"
    ```toml
    [wokwi]
    version = 1
    elf = ".pio/build/uno/firmware.elf"
    firmware = ".pio/build/uno/firmware.hex"
    ```
-   Contoh `wokwi.toml` untuk board "DOIT ESP32 DEVKIT V1"
    ```toml
    [wokwi]
    version = 1
    elf = ".pio/build/esp32doit-devkit-v1/firmware.elf"
    firmware = ".pio/build/esp32doit-devkit-v1/firmware.bin"
    ```
-   Perhatikan bahwa file "elf" dan "firmware" merupakan hasil build

#### Updating Diagram

Dengan extension, ketika file `diagram.json` dibuka, akan muncul rangkaian seperti di Wokwi versi Web. Namun, editing rangkaian di VS Code butuh versi premium. Solusinya:

-   Edit rangkaian di Wokwi versi Web
-   Copy teks di `diagram.json` pada Wokwi versi Web
-   Buka `diagram.json` pada VS Code dengan Text Editor: klik kanan pada file > "Open With..." > "Text Editor"
-   Paste teks ke `diagram.json` pada VS Code lalu Save

#### Running Simulation

-   Buka `diagram.json` sehingga terlihat rangkaian nya
-   Klik tombol Play untuk start simulation
-   Pastikan tab yang menjalankan simulasi selalu terbuka & terlihat, jika tidak simulasi akan berhenti, bisa gunakan fitur Split Editor

### C/C++ - VS Code Extension (not compulsory)

#### Install

[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

#### Description

C/C++ Extensions memberikan fitur intellisense, debugging, code browsing untuk C/C++ atau dalam hal ini bahasa Arduino.

## Node-RED related

### NodeJS

#### Install

[NodeJS](https://nodejs.org/en/download)

#### Note !!!

Terkadang NodeJS sudah terinstall di komputer. Untuk mengeceknya, buka terminal, lalu coba perintah: `node`

#### Description

NodeJS dibutuhkan untuk instalasi dan running Node-RED karena Node-RED dibuat di atas NodeJS.

### Node-RED

#### Install

```bash
npm install -g --unsafe-perm node-red
```

#### Description

[Node-RED](https://nodered.org/) adalah open-source flow-based low-code platform dengan berbagai fitur dan library. Dalam project di sini, Node-RED digunakan untuk berkomunikasi dengan MQTT dan Firebase serta membuat Dashboard

#### Running

-   Jalankan perintah `node-red` pada terminal, jika perintah itu tidak dikenali, coba lagi di "Node.js command prompt"
-   Jika sudah berjalan, biarkan terminal dan jangan ditutup
-   Buka tampilan Node-RED di [http://localhost:1880](http://localhost:1880)
-   Lebih lanjut, lihat video tutorial (ada banyak di Youtube) atau baca [Dokumentasi Node-RED](https://nodered.org/docs/)

## MicroPython related

**Note**: Tidak perlu install MicroPython di komputer karena yang nanti akan menggunakan MicroPython adalah IoT device (seperti ESP32). Yang disiapkan di komputer adalah tools untuk develop program MicroPython dan upload program MicroPython ke IoT device.

### Python

#### Install

[Python](https://www.python.org/downloads/)

#### Note !!!

Terkadang Python sudah terinstall di komputer. Bahkan, bisa jadi Python ikut terinstal ketika instalasi NodeJS. Untuk mengeceknya, buka terminal, lalu coba perintah: `python`

#### Description

Python dibutuhkan untuk mendukung Python Extensions juga karena ada beberapa tools yang perlu diinstal dengan `pip`

### Python - VS Code Extension (not compulsory)

#### Install

[Python](https://marketplace.visualstudio.com/items?itemName=ms-python.python) dan [Pylance](https://marketplace.visualstudio.com/items?itemName=ms-python.vscode-pylance)

#### Description

Kombinasi keduanya memberikan fitur intellisense, debugging, type checking, formatting, dan lainnya. Namun, untuk case MicroPython, diperlukan MicroPython Stubs.

### MicroPython Stubs (not compulsory)

#### Install

1. Buka terminal pada folder project
1. Install MicroPython stub package sesuai IoT device:

    ```bash
    pip install <micropython-stub-package> --target typings --no-user

    # Example
    pip install micropython-esp32-stubs --target typings --no-user
    ```

    Perintah tersebut akan menghasilkan folder `typings` di project, folder itu berisi MicroPython Stubs

#### Description

[MicroPython Stubs](https://github.com/Josverl/micropython-stubs) memungkinkan intellisense dan type checking dari Python Extensions bisa bekerja dengan baik untuk case MicroPython.

### Tool mpremote and Simulation with Wokwi

#### Install

```bash
pip install mpremote
```

#### Description

Tool `mpremote` penting untuk simulasi/deployment karena dapat menghubungkan komputer tempat development dengan IoT device tempat deployment.

#### Simulation with Wokwi

-   Download [firmware MicroPython](https://micropython.org/download/) sesuai IoT Device, misalnya [firmware MicroPython ESP32](https://micropython.org/download/ESP32_GENERIC/)
-   Taruh file firmware di folder project
-   Pada file `wokwi.toml`:
    ```toml
    [wokwi]
    version = 1
    elf = "<firmware_file.bin>"
    firmware = "<firmware_file.bin>"
    rfc2217ServerPort = 4000
    ```
-   Jalankan simulasi Wokwi seperti biasa (buka `diagram.json`, lalu klik Play)
-   Buka terminal pada folder project, lalu jalankan:
    ```bash
    python -m mpremote connect port:rfc2217://localhost:4000 run main.py
    ```

## External Services

### Blynk

#### Description

Blynk merupakan IoT Platform yang cukup beginner-friendly dengan fitur yang cukup banyak. Blynk bisa digunakan untuk perekaman data, kontrol IoT device, pembuatan dashboard, dan lainnya.

#### Create Blynk Project

-   Buka [Blynk.Console](https://blynk.cloud/dashboard), register/login seperti biasa
-   Buat Template, "Developer Zone" > "Templates" > "New Template", bagian "Connection Type" biasanya menggunakan "WiFi"
-   Buka Template yang sudah dibuat, lalu "Add first Device"
-   Simpan Template ID, Template Name, dan AuthToken untuk dipakai di kode. Template ID dan Template Name berkaitan dengan Template sementara AuthToken berkaitan dengan Device
-   Pada Template, atur "Datastreams" dan "Web Dashboard" sesuai kebutuhan project
-   Lebih lanjut, lihat video tutorial (ada banyak di Youtube) atau baca [Dokumentasi Blynk](https://docs.blynk.io/en)

### MQTT Broker

#### Description

MQTT merupakan protokol komunikasi dengan konsep publish/subscribe sementara MQTT Broker merupakan perantara/server yang menjembatani komunikasi tersebut. MQTT banyak digunakan untuk komunikasi dengan IoT device

#### Usage

Cara termudah dan tercepat adalah menggunakan Online MQTT Broker, misalnya broker dengan alamat `broker.emqx.io` dan port `1883`. Cara lainnya adalah dengan menjalankan broker sendiri di lokal, misalnya dengan [mosquitto](https://mosquitto.org/download)

### Firebase

#### Description

Firebase adalah application development platform yang meliputi berbagai fitur seperti authentication, database, dan cloud function. Dalam IoT, Firebase bisa untuk komunikasi seperti MQTT, perekaman data, dan lainnya.

#### Create Firebase Project

Tutorial bagus: [Firebase Project for ESP32](https://randomnerdtutorials.com/esp32-firebase-realtime-database)

## Additional

### Arduino IDE

[Arduino IDE](https://www.arduino.cc/en/software) bisa menjadi alternatif yang lebih sederhana untuk VS Code + PlatformIO. Arduino IDE memiliki berbagai fitur dasar seperti Code Editor, Serial Monitor, Library Installer, serta Build & Upload dengan tampilan yang user-friendly. Arduino IDE bisa digunakan pada berbagai board Arduino, board ESP32, atau lainnya. Namun, fiturnya terbatas dan tidak ada integrasi dengan Wokwi.

### Arduino - VS Code Extension

[Arduino Extensions](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino) juga bisa menjadi alternatif untuk VS Code + PlatformIO.

### Other VS Code Extension

VS Code memiliki banyak sekali Extensions untuk berbagai keperluan, baik yang sifatnya umum atau pun yang terkait IoT. Penggunaan Extensions dapat secara signifikan meningkatkan produktivitas.
