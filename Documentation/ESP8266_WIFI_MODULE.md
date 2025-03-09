# ESP8266 WiFi Module

This repository provides setup instructions and example code for using the **ESP8266 WiFi module** with an Arduino to enable wireless communication.

## 📌 Features
- Connects Arduino to WiFi for IoT applications
- Supports HTTP web server functionality
- Can control electrical appliances remotely via a web interface
- Compatible with Arduino Uno, Mega, and Nano

---

## 🛠 Requirements
### 🔹 Hardware:
- ESP8266 WiFi Module
- Arduino Board (Uno, Mega, Nano, etc.)
- Jumper Wires
- Relay Module (for appliance control)
- Power Supply (3.3V for ESP8266)

### 🔹 Software:
- **Arduino IDE** (Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software))
- **ESP8266WiFi Library** (Install from Arduino Library Manager)

---

## ⚡ Wiring Connections

| **ESP8266 Pin** | **Arduino Pin** |
|---------------|---------------|
| **VCC**      | **3.3V**       |
| **GND**      | **GND**        |
| **TX**       | **RX (D0)**    |
| **RX**       | **TX (D1)**    |
| **CH_PD**    | **3.3V**       |

📌 **Important:** ESP8266 operates at **3.3V**. Do not connect it to 5V, as it may damage the module.

---

## 📥 Library Installation
1. Open **Arduino IDE**
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for **ESP8266WiFi**
4. Install the library

---

## 🚀 Example Code
Upload the following code to test your ESP8266 module:

```cpp
#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    client.println("<h1>ESP8266 Web Server</h1>");
    client.stop();
  }
}
```

🔹 **Modify `ssid` and `password`** to match your WiFi credentials.
🔹 Open **Serial Monitor** (115200 baud) to check the connection status.

---

## 📌 Notes
- Use **level shifter or voltage divider** for RX pin (ESP8266 runs on 3.3V logic).
- If ESP8266 does not respond, **press RESET** or **flash the firmware**.
- Check if the **baud rate** matches in Serial Monitor.

---

## 📜 License
This project is open-source and available under the **MIT License**.

---

## 🙌 Credits
- Developed by **Thiruselvan - [ThiruXD](https://github.com/ThiruXD)**
- Based on the work of **Arduino Community**
- GitHub Repository: [Arduno Based Project](https://github.com/ThiruXD/Arduno-Based-Project)

🚀 **Happy IoT Development!** 🎉
