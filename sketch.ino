#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include "time.h"

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800; 
const int   daylightOffset_sec = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  WiFi.begin(ssid, password);
  lcd.setCursor(0, 0);
  lcd.print("Connecting....");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connected.");

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  delay(2000);
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeInfo)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time Error");
    return;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.setCursor(6,0);
  lcd.print(&timeinfo, "%d/%m/%Y");

  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(6,1);
  lcd.print(&timeinfo, "%H:%M:%S");

  delay(1000);
}