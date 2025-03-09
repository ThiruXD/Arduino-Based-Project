# Power Supply & Circuit Connections

This document provides details on the **Power Supply & Circuit Connections** for the **Smart Remote for Controlling Electrical Appliances** project.

## 📌 Overview
The system requires multiple voltage levels to operate different components safely:
- **5V** for Arduino Uno and Relay Module
- **3.3V** for ESP8266 WiFi Module
- **External AC Power** for connected appliances

## 🛠 Power Supply Requirements
### 🔹 Components:
- **5V DC Adapter (1A or higher)**
- **3.3V Regulator (AMS1117 or similar)**
- **Power Distribution Board (optional)**
- **Jumper Wires**
- **AC Power Source (for appliances)**

## ⚡ Wiring Connections

| **Component**          | **Power Source**  | **Voltage Level** |
|----------------------|----------------|-----------------|
| **Arduino Uno**      | **5V Adapter**  | **5V DC**       |
| **ESP8266 WiFi**     | **AMS1117 Regulator** | **3.3V DC**       |
| **Relay Module**     | **Arduino 5V Pin**  | **5V DC**       |
| **LCD Display (I2C)**| **Arduino 5V Pin**  | **5V DC**       |

📌 **Note:** The **ESP8266 WiFi module** should NOT be powered directly from **Arduino’s 5V pin**. Use a **3.3V regulator** to prevent damage.

## ⚠️ Safety Precautions
- Always **disconnect power before wiring changes**.
- Ensure proper **voltage regulation** to avoid damage to components.
- Use **insulated connections** for high-voltage AC wiring.
- If using **high-power appliances**, consider using an **isolated power source** for safety.

## 🚀 Example Circuit Diagram
A circuit diagram illustrating the connections can be added here.

## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **[Arduino Community](https://forum.arduino.cc/)**
- GitHub Repository: **[Arduno Based Project](https://github.com/ThiruXD/Arduno-Based-Project)**
- Part of the **Final Year Project** at [P.S.V Polytechnic College](https://g.co/kgs/e5nvPrM)

🚀 **Safe and Efficient Power Management!** 🎉
