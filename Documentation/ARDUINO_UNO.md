# Arduino Uno - Smart Remote for Controlling Electrical Appliances

## 📖 Overview
The **Arduino Uno** is the central microcontroller for our **Smart Remote for Controlling Electrical Appliances** project. It communicates with the **ESP8266 WiFi Module** to receive commands and controls the **LCD Display and Relay Module** to operate appliances.

## 🔧 Features
- Acts as the **main controller** for the project.
- Communicates with **ESP8266 via SoftwareSerial**.
- Controls **2-Channel Relay Module** to switch appliances ON/OFF.
- Displays messages received from the web interface on **16x2 LCD**.

## 📜 Pin Connections

| **Arduino Uno** | **Connected To** |
|---------------|----------------|
| **TX (Pin 1)** | ESP8266 RX *(through voltage divider)* |
| **RX (Pin 0)** | ESP8266 TX |
| **Pin 7** | Relay Module IN1 |
| **A4 (SDA)** | LCD I2C SDA |
| **A5 (SCL)** | LCD I2C SCL |
| **5V** | LCD Display & Relay Module |
| **3.3V** | ESP8266 |
| **GND** | Common Ground |

## 🔌 How It Works
1. **Receives commands** from ESP8266 (e.g., turn ON/OFF appliances).
2. **Sends signals** to the **relay module** to switch appliances.
3. **Displays text** received via the web interface on the LCD.

## 🚀 Code Example (Arduino Uno)
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define RELAY_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        if (command == "LIGHT_ON") {
            digitalWrite(RELAY_PIN, HIGH);
        } else if (command == "LIGHT_OFF") {
            digitalWrite(RELAY_PIN, LOW);
        } else {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Message:");
            lcd.setCursor(0, 1);
            lcd.print(command);
        }
    }
}
```


## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: **[Arduino Based Project](https://github.com/ThiruXD/Arduino-Based-Project)**
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Happy Arduino Uno Development!** 🎉
