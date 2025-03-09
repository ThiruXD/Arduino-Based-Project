#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "moto g45 - ThiruXD";  // Replace with your WiFi SSID
const char* password = "1234567890";  // Replace with your WiFi Password

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);  // Communicate with Arduino
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  // Web Page
  server.on("/", []() {
    server.send(200, "text/html", 
      "<h2>Smart Remote</h2>"
      "<button onclick=\"fetch('/toggle?device=fan')\">Fan ON/OFF</button>"
      "<button onclick=\"fetch('/toggle?device=light')\">Light ON/OFF</button><br><br>"
      "<input type='text' id='lcdText' placeholder='Enter text'>"
      "<button onclick=\"fetch('/display?text='+document.getElementById('lcdText').value)\">Send to LCD</button>"
      "<script>function fetch(url){var x=new XMLHttpRequest();x.open('GET',url,true);x.send();}</script>"
    );
  });

  server.on("/toggle", []() {
    String device = server.arg("device");
    if (device == "fan") Serial.println("FAN_TOGGLE");
    else if (device == "light") Serial.println("LIGHT_TOGGLE");
    server.send(200, "text/plain", "OK");
  });

  server.on("/display", []() {
    String text = server.arg("text");
    Serial.println("LCD:" + text);
    server.send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
