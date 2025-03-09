# Arduino Uno

This document provides details on using the **Arduino Uno** in the **Smart Remote for Controlling Electrical Appliances** project.

## 📌 Overview
The **Arduino Uno** serves as the main microcontroller, handling input signals, processing data, and controlling output devices such as the **ESP8266 WiFi module, LCD display, and relay module**.

## 🛠 Requirements
### 🔹 Hardware:
- **Arduino Uno**
- **ESP8266 WiFi Module**
- **16x2 LCD with I2C Module**
- **Relay Module**
- **Jumper Wires**
- **Power Supply (5V & 3.3V as required)**

### 🔹 Software:
- **Arduino IDE** ([Download](https://www.arduino.cc/en/software))
- Required Libraries:
  - `ESP8266WiFi.h`
  - `LiquidCrystal_I2C.h`
  - `Wire.h`

---

## ⚡ Wiring Connections
The **Arduino Uno** interfaces with multiple components as follows:

| **Component**   | **Arduino Uno Pins** |
|---------------|-------------------|
| **ESP8266 TX**  | **D0 (RX)**        |
| **ESP8266 RX**  | **D1 (TX)**        |
| **LCD SDA**     | **A4 (SDA)**       |
| **LCD SCL**     | **A5 (SCL)**       |
| **Relay IN**    | **D7**             |

📌 **Note:** If using **ESP8266**, ensure **voltage level shifting** for safe communication (ESP8266 works on 3.3V logic, while Arduino Uno operates on 5V).

---

## 🚀 Example Code
This sample sketch initializes the **Arduino Uno**, connects to WiFi, and displays a message on the LCD.

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected!");
}

void loop() {}
```

---

## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: **[Arduno Based Project](https://github.com/ThiruXD/Arduno-Based-Project)**
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Happy Arduino Uno Development!** 🎉
