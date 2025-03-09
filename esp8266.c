#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "moto g45 - ThiruXD";      // Replace with your WiFi SSID
const char* password = "1234567890";  // Replace with your WiFi password

ESP8266WebServer server(80);

#define LED_RELAY 2   // Change GPIO pin if needed
#define FAN_RELAY 4   // Change GPIO pin if needed

void setup() {
    Serial.begin(115200);
    
    pinMode(LED_RELAY, OUTPUT);
    pinMode(FAN_RELAY, OUTPUT);
    
    digitalWrite(LED_RELAY, HIGH);  // Start OFF (Active LOW Relay)
    digitalWrite(FAN_RELAY, HIGH);  // Start OFF

    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/led_on", []() {
        digitalWrite(LED_RELAY, LOW);
        server.send(200, "text/plain", "LED ON");
    });
    server.on("/led_off", []() {
        digitalWrite(LED_RELAY, HIGH);
        server.send(200, "text/plain", "LED OFF");
    });
    server.on("/fan_on", []() {
        digitalWrite(FAN_RELAY, LOW);
        server.send(200, "text/plain", "Fan ON");
    });
    server.on("/fan_off", []() {
        digitalWrite(FAN_RELAY, HIGH);
        server.send(200, "text/plain", "Fan OFF");
    });

    server.begin();
    Serial.println("HTTP Server Started!");
}

void loop() {
    server.handleClient();
}

void handleRoot() {
    server.send(200, "text/html",
        "<h2>ESP8266 Relay Control</h2>"
        "<button onclick=\"fetch('/led_on')\">Turn LED ON</button>"
        "<button onclick=\"fetch('/led_off')\">Turn LED OFF</button><br><br>"
        "<button onclick=\"fetch('/fan_on')\">Turn Fan ON</button>"
        "<button onclick=\"fetch('/fan_off')\">Turn Fan OFF</button>"
    );
}
