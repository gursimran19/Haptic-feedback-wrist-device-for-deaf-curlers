
## Overview
VibeSweep is a wireless wearable guidance system designed to communicate directional and intensity-based instructions using vibration feedback. The system consists of a **controller unit** and one or more **receiver devices**, enabling real-time, low-latency communication through ESP-NOW on ESP32 microcontrollers.

The project focuses on embedded systems design, wireless communication, and human–device interaction.

---

## System Architecture
VibeSweep is composed of two main components:
- **VibeSweep Controller**
- **VibeSweep Receiver**

Both components use ESP32 boards and communicate wirelessly using **ESP-NOW**.

---

## VibeSweep Controller

### Hardware Components
- WEMOS Lolin32 ESP32 board (ESP-NOW enabled)
- Custom 3D-printed plastic enclosure
- Left and right control potentiometers
- 800 mAh rechargeable battery
- Rear clip for wearable attachment

### Functionality
- Controls vibration intensity of paired receiver devices
- Supports three vibration levels:
  - **High**
  - **Medium**
  - **Low**
- Sends wireless control signals to receiver devices
- Designed to clip onto clothing such as:
  - Pockets
  - Belts
  - Jackets

---

## VibeSweep Receiver

### Hardware Components
- WEMOS Lolin32 ESP32 board (ESP-NOW enabled)
- Pre-fabricated enclosure with adjustable buckle straps
- Left and right position switch
- Vibration motor for haptic feedback
- 800 mAh rechargeable battery

### Functionality
- Receives wireless signals from the controller
- Translates control signals into vibration-based instructions
- Uses vibration feedback to communicate directional or positional information to the wearer
- Designed to be worn securely using adjustable straps

---

## Communication
- **Wireless Protocol:** ESP-NOW
- Enables low-latency, peer-to-peer communication between ESP32 devices
- Optimized for real-time feedback without requiring Wi-Fi infrastructure

---

## Key Features
- Wearable embedded system design
- Wireless real-time communication
- Haptic feedback interface
- Portable and battery-powered hardware
- Custom enclosures and ergonomic mounting

---

## Applications
- Directional guidance systems
- Wearable feedback devices
- Assistive or training technologies
- Embedded systems and IoT experimentation

---

## Technologies Used
- ESP32 (WEMOS Lolin32)
- ESP-NOW wireless protocol
- Embedded C / Arduino framework
- 3D-printed enclosures
- Battery-powered wearable hardware

---

## Author
**Gursimran Singh**  
