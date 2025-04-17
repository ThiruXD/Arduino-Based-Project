# 16x2 LCD Display with I2C - Smart Remote for Controlling Electrical Appliances

## 📖 Overview
The **16x2 LCD Display with I2C** is used in our project to show messages received from the **web interface**. The display is connected to the **Arduino Uno** via the **I2C interface**.

## 🔧 Features
- 16 characters per row, 2 rows.
- Uses **I2C communication** (SDA & SCL).
- Reduces wiring compared to standard LCD.

## 📜 Pin Connections

| **LCD I2C Module** | **Arduino Uno** |
|-------------------|---------------|
| **VCC** | 5V |
| **GND** | GND |
| **SDA** | A4 |
| **SCL** | A5 |

## 🚀 Code Example
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
    lcd.init();    
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Smart Remote");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print("ESP8266 Control");
    delay(2000);
    lcd.clear();
}
```
## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: **[Arduino Based Project](https://github.com/ThiruXD/Arduino-Based-Project)**
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Happy IoT Development!** 🎉