# 🕒 ESP32 NTP Digital Clock with I2C LCD

A simple IoT-based digital clock built using ESP32, NTP (Network Time Protocol), and a 16x2 I2C LCD display.  
The ESP32 connects to WiFi, fetches the current time from an NTP server, and displays the live date and time on the LCD.

---

## 🚀 Features

- Connects ESP32 to WiFi
- Fetches real-time data from `pool.ntp.org`
- Displays:
  - 📅 Date (DD/MM/YYYY)
  - ⏰ Time (HH:MM:SS)
- Auto-updates every second
- GMT offset configured for India (UTC +5:30)
- Works in simulation (Wokwi) and real hardware

---

## 🛠️ Hardware Used

- ESP32
- 16x2 I2C LCD Display (I2C address: 0x27)
- Jumper wires

---

## 🔌 Circuit Connections

| LCD Pin | ESP32 Pin |
|----------|----------|
| VCC      | 5V       |
| GND      | GND      |
| SDA      | GPIO 21  |
| SCL      | GPIO 22  |

---

## 📚 Libraries Required

Install these libraries in Arduino IDE:

- LiquidCrystal_I2C
- WiFi.h (built-in for ESP32)
- time.h (built-in for ESP32)

---

## 🌐 WiFi Configuration

```cpp
const char* ssid     = "Wokwi-GUEST";
const char* password = "";
```

Update these values if using real hardware.

---

## ⏱️ Time Configuration

```cpp
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800; 
const int   daylightOffset_sec = 0;
```

- 19800 seconds = UTC +5:30 (India Standard Time)

Change the GMT offset according to your timezone.

---

## 🧠 How It Works

1. ESP32 connects to WiFi.
2. NTP server (pool.ntp.org) provides current time.
3. `configTime()` configures the system clock.
4. `getLocalTime()` fetches structured time data.
5. LCD prints formatted:
   - Date → `%d/%m/%Y`
   - Time → `%H:%M:%S`
6. Updates every second.

---

## 📂 Example Output

```
Date: 16/02/2026
Time: 10:45:32
```

---


## 🔐 License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

You are free to:
- Use
- Modify
- Distribute

Under the terms of the GPL-3.0 license.

---

## 📌 Future Improvements

- Add RTC module (DS3231) for offline backup
- Add alarm functionality
- Add temperature & humidity display
- Add 12/24 hour format toggle
- Add web dashboard integration
- Add automatic timezone detection

---

## 👨‍💻 Author

Amith E.K.  
ESP32 IoT Project – 2026
