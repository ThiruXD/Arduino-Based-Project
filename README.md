# Arduno Based Smart Remote for Controlling Electrical Appliances 

## 📌 Project Overview
This is a final year project of [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM), **Arduino-Based Smart Remote for Home Appliances Using ESP8266**, enables wireless control of home appliances like lights and fans using an ESP8266 module and an Arduino microcontroller. The system features a web interface for easy operation.

## 🚀 Features
- Wireless control of electrical appliances using ESP8266 Wi-Fi module
- Web-based interface for switching ON/OFF devices
- LCD display for status updates
- Low-cost and easy-to-build solution for smart home automation

## 🛠 Hardware Components
| Component         | Quantity |
|------------------|----------|
| Arduino Uno      | 1        |
| ESP8266 Wi-Fi Module | 1    |
| 16x2 LCD Display (I2C) | 1   |
| Relay Module (2-Channel) | 1 |
| Light Bulb (for testing) | 1 |
| Fan (for testing) | 1 |
| Jumper Wires     | Multiple |

## 👨‍💻 Team Members
- **Thiruselvan** - Project Manager & Backend Developer  
- **M Denish** - Assistant Documentation Manager  
- **RajaPriyan** - Testing & Debugging Specialist  
- **Kishore** - Documentation & Report Manager  
- **Kumaresh** - Web UI/UX Designer  
- **Manikandan** - Hardware Specialist  

## 🔌 Wiring Connections
### **ESP8266 to Arduino**
| ESP8266 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 3.3V        |
| GND        | GND         |
| TX         | RX (D0)     |
| RX         | TX (D1)     |

### **16x2 I2C LCD to Arduino**
| LCD Pin | Arduino Pin |
|---------|------------|
| VCC     | 5V         |
| GND     | GND        |
| SDA     | A4         |
| SCL     | A5         |

### **Relay to Arduino**
| Relay Pin | Arduino Pin |
|-----------|------------|
| VCC       | 5V         |
| GND       | GND        |
| IN1       | D7         |
| IN2       | D8         |

## 📜 Installation & Setup
### **1️⃣ Install Required Libraries**
1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search and install:
   - `ESP8266WiFi`
   - `LiquidCrystal_I2C` (by Frank de Brabander)

### **2️⃣ Uploading Code to Arduino**
- Connect Arduino to PC via USB
- Select the correct **board (Arduino Uno)** and **COM port** in Arduino IDE
- Upload the firmware

## 💻 Web Interface
Once the ESP8266 is connected to Wi-Fi, access the web interface via the assigned **IP address** in the browser. You can control devices with ON/OFF buttons.

## 📜 Example Code
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
  // Main loop for controlling appliances
}
```

## 📌 Project Repository
[GitHub Repository](https://github.com/your-repo-link)

## 📜 License
This project is licensed under the **MIT License**.

---
✅ *Developed by our team for final year project implementation.*
