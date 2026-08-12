# Cognevance_SmartAgriculture
IoT-Based Smart Agriculture Monitoring System using ESP32 and Wokwi for soil moisture, temperature, and humidity monitoring with IoT dashboard and automated irrigation control.
# Smart Agriculture System

## 1. Project Overview

The Smart Agriculture System is an embedded IoT-based project designed to demonstrate automatic irrigation, sensor monitoring, and cloud-based visualization.

The ESP32 acts as the main controller. A DHT22 sensor measures temperature and humidity, while a potentiometer is used as a simulated soil-moisture sensor in Wokwi.

Based on the soil moisture level, the ESP32 automatically controls a relay connected to a stepper motor, which represents the water pump. An LED provides a visual indication of the pump status.

The sensor data and system status are displayed on a Blynk IoT dashboard.

The complete system was developed and tested using the Wokwi online simulation platform.

---

## 2. Objectives

The main objectives of this project are:

- To understand ESP32-based IoT systems.
- To interface a DHT22 sensor with ESP32.
- To simulate soil moisture sensing.
- To implement automatic irrigation control.
- To control a relay using ESP32.
- To monitor sensor values using Blynk.
- To display real-time agriculture parameters on an IoT dashboard.
- To test the complete system using Wokwi simulation.

---

## 3. System Components

### Hardware / Simulated Components

- ESP32 DevKit
- DHT22 Temperature and Humidity Sensor
- Potentiometer as simulated Soil Moisture Sensor
- Relay Module
- Stepper Motor as simulated Water Pump
- LED
- Resistor
- Connecting wires

### Software and Tools

- Arduino C/C++
- Wokwi Simulator
- Blynk IoT
- GitHub

---

## 4. System Architecture

```text
DHT22
  │
  ├── Temperature
  └── Humidity
          │
          ↓
        ESP32
          ↑
          │
Potentiometer
(Soil Moisture)
          │
          ↓
   Decision Making
          │
          ↓
    Soil Moisture
       < 30%
          │
          ↓
       Relay
          │
          ↓
    Water Pump
          │
          ↓
       LED

ESP32
  │
  ↓
Blynk Cloud
  │
  ↓
Blynk Dashboard
