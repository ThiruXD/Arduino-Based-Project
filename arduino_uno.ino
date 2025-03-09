#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C Address for LCD

#define FAN_RELAY 7
#define LIGHT_RELAY 8

void setup() {
  pinMode(FAN_RELAY, OUTPUT);
  pinMode(LIGHT_RELAY, OUTPUT);
  digitalWrite(FAN_RELAY, HIGH);
  digitalWrite(LIGHT_RELAY, HIGH);
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "FAN_TOGGLE") {
      digitalWrite(FAN_RELAY, !digitalRead(FAN_RELAY));
    } 
    else if (command == "LIGHT_TOGGLE") {
      digitalWrite(LIGHT_RELAY, !digitalRead(LIGHT_RELAY));
    } 
    else if (command.startsWith("LCD:")) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(command.substring(4));  // Display text on LCD
    }
  }
}
