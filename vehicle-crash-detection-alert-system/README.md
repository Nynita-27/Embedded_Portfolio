# Vehicle Fall & Crash Detection with Real-Time Alert System
  A real-time embedded safety system that automatically detects vehicle falls and crashes, pinpoints the GPS location, alerts nearby vehicles wirelessly, and sends emergency SMS + voice call — all within seconds.

> Project developed as part of **PG-Diploma in Embedded System Design** at **C-DAC Hyderabad** (February 2025)
  ## 🧠 How It Works
  
  1. STM32F411RE continuously reads acceleration data from ADXL345 and impact signal from SW420
  2. When tilt angle exceeds 60° AND impact is detected simultaneously, fall/crash is confirmed
  3. STM32 fetches real-time GPS coordinates from GPS Neo-6M
  4. STM32 sends the formatted alert message to ESP32 via UART
  5. ESP32 broadcasts alert to nearby vehicles using ESP-NOW protocol
  6. ESP32 sends SMS with Google Maps link to emergency contact via Twilio API
  7. ESP32 initiates an automated voice call to emergency contact
  8. Receiving vehicles display the alert on their OLED screen
     
  ## ⚙️ Hardware Components
  
  | Component | Role | Interface |
  |-----------|------|------------|
  | STM32F411RE (Nucleo) | Main microcontroller, sensor processing | - |
  | ESP32 | Wireless communication, Twilio alerts | UART |
  | ADXL345 | 3-axis accelerometer for tilt/fall detection | I2C |
  | SW420 | Vibration/impact sensor for crash detection | GPIO |
  | GPS Neo-6M | Real-time location tracking | UART |
  | OLED (128x64, SSD1306) | Status display on vehicle | I2C |

  ## 🛠️ Software & Tools

  - STM32CubeIDE — STM32 firmware development (C language, HAL libraries)
  - Arduino IDE — ESP32 firmware development
  - ESP-NOW Protocol — Peer-to-peer wireless communication between ESP32 devices
  - Twilio API — SMS alerts and automated voice calls
  - NMEA Parsing — Extracting GPS coordinates from GPRMC sentences
   
   ## ✅ Results

  - Fall/crash detection working accurately with ADXL345 + SW420 combination
  - GPS coordinates captured and included in alert messages
  - SMS with Google Maps link delivered successfully via Twilio
  - Automated voice call triggered on crash detection
  - Nearby vehicle received ESP-NOW alert and displayed it on OLED
  - End-to-end alert delivered within seconds of crash event

  ## 🔮 Future Scope
  
  - Integration with smart helmets for rider fall detection
  - Real-time video streaming from crash site
  - Solar-powered operation for continuous reliability

*Institution:** C-DAC Hyderabad — PG-Diploma in Embedded System Design (Feb 2025)
