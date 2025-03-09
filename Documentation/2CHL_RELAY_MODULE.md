# 2-Channel Relay Module

This document provides details on using the **2-Channel Relay Module** in the **Smart Remote for Controlling Electrical Appliances** project.

## 📌 Overview
The **2-Channel Relay Module** is used to control **high-voltage appliances** like lights and fans using low-voltage signals from an **Arduino Uno** or **ESP8266**. It acts as an electronic switch that allows the microcontroller to control AC or DC loads.

## 🛠 Requirements
### 🔹 Hardware:
- **2-Channel Relay Module** (5V)
- **Arduino Uno / ESP8266**
- **Jumper Wires**
- **AC/DC Load (Bulb, Fan, etc.)**
- **External Power Supply (if required)**

### 🔹 Software:
- **Arduino IDE** ([Download](https://www.arduino.cc/en/software))

---

## ⚡ Wiring Connections
The **Relay Module** interfaces with **Arduino Uno** or **ESP8266** as follows:

| **Relay Module Pins** | **Arduino Uno / ESP8266 Pins** |
|---------------------|----------------------|
| **VCC**            | **5V (Arduino) / 3.3V (ESP8266)** |
| **GND**            | **GND**               |
| **IN1**            | **D7**                |
| **IN2**            | **D8**                |

📌 **Note:**
- If using **ESP8266**, a **transistor circuit or relay module with 3.3V logic support** is recommended.
- Ensure that AC loads are connected safely with proper insulation.

---

## 🚀 Example Code
This sample sketch **controls two relays**, turning them **ON and OFF alternately** every **5 seconds**.

```cpp
#define RELAY_1 7
#define RELAY_2 8

void setup() {
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
}

void loop() {
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, LOW);
  delay(5000);
  
  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, HIGH);
  delay(5000);
}
```

---

## 📜 Safety Precautions
- Ensure **proper insulation** when dealing with **high-voltage AC connections**.
- **Do not exceed the rated current and voltage** of the relay contacts.
- If controlling **high-power appliances**, use a **separate power source** for safety.

---

## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: [Arduno Based Project](https://github.com/ThiruXD/Arduno-Based-Project)
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Safe and Smart Home Automation!** 🎉
