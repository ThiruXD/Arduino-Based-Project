# 16x2 LCD Display with I2C Module

This repository provides setup instructions and example code for using a **16x2 LCD display with an I2C module** on an Arduino.

## 📌 Features
- Uses I2C interface (SDA, SCL) to communicate with the LCD
- Requires only two pins, saving digital pins for other components
- Supports 16 characters per row and 2 rows
- Adjustable backlight and contrast

---

## 🛠 Requirements
### 🔹 Hardware:
- Arduino Board (Uno, Mega, Nano, etc.)
- 16x2 LCD Display with I2C Module
- Jumper Wires

### 🔹 Software:
- **Arduino IDE** (Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software))
- **LiquidCrystal I2C Library** (Install from Arduino Library Manager)

---

## ⚡ Wiring Diagram
Connect the LCD module to the Arduino as follows:

| **LCD Pin** | **Arduino UNO Pin** |
|------------|----------------|
| **VCC** | **5V** |
| **GND** | **GND** |
| **SDA** | **A4** |
| **SCL** | **A5** |

📌 **For Arduino Mega:**
- **SDA → Pin 20**
- **SCL → Pin 21**

---

## 📥 Library Installation
1. Open **Arduino IDE**
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for **LiquidCrystal I2C**
4. Install the library by **Frank de Brabander**

---

## 🚀 Example Code
Upload the following code to test your LCD module:

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 if needed

void setup() {
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
}

void loop() {
}
```

🔹 If the LCD does not display anything:
- Run an **I2C Scanner** to check the address (might be `0x3F` instead of `0x27`)
- Adjust the **blue contrast potentiometer** on the back of the module

---

## 🔍 I2C Address Scanner (Debugging)
Use this code to find the correct I2C address:

```cpp
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Scanning for I2C devices...");
  Wire.begin();
}

void loop() {
  byte error, address;
  int nDevices = 0;
  
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.println(address, HEX);
      nDevices++;
    }
  }
  
  if (nDevices == 0) Serial.println("No I2C devices found");
  delay(5000);
}
```

---

## 📌 Notes
- If you see **garbled characters** or **no display**, try adjusting the **contrast**.
- Double-check **wiring connections** and **I2C address**.
- Ensure **LiquidCrystal I2C library** is installed.

---

## 📜 License
This project is open-source and available under the **MIT License**.

---

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: [Arduno Based Project](https://github.com/ThiruXD/Arduno-Based-Project)
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Happy Coding!** 🎉
