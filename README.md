# Cognevance_IoT_SmartAgriculture

An IoT-Based Smart Agriculture Monitoring System developed using an ESP32/ESP8266 microcontroller and IoT sensors to monitor soil and environmental conditions in real time. The system collects soil moisture, temperature, and humidity data, sends the readings to a cloud-based IoT platform, and automatically controls irrigation based on soil moisture conditions.

## Project Overview

Agriculture requires regular monitoring of soil and environmental conditions to maintain healthy crop growth and use water efficiently.

This project implements an IoT-based smart agriculture monitoring system that continuously monitors:

* Soil moisture
* Temperature
* Humidity

The collected sensor data is transmitted through an ESP32/ESP8266 to an IoT cloud platform. A dashboard is used for real-time monitoring, while an automated irrigation system controls a water pump based on the soil moisture level.

## Objectives

The main objectives of this project are:

1. Monitor soil moisture, temperature, and humidity in real time.
2. Interface multiple sensors with an ESP32/ESP8266.
3. Transmit sensor data to an IoT cloud platform.
4. Create a dashboard for real-time monitoring.
5. Implement automatic irrigation control based on soil moisture.
6. Analyze the collected sensor data.
7. Test communication between the embedded device and IoT platform.
8. Test and verify the complete automation workflow.
9. Document the system architecture, implementation, and testing results.

## System Features

* Real-time soil moisture monitoring
* Temperature monitoring
* Humidity monitoring
* IoT cloud connectivity
* Real-time dashboard
* Automatic irrigation control
* Sensor-based decision making
* Remote monitoring
* Sensor data analysis
* Embedded system testing

## Hardware Components

| Component            | Purpose                                    |
| -------------------- | ------------------------------------------ |
| ESP32 / ESP8266      | Main microcontroller and IoT communication |
| Soil Moisture Sensor | Measures soil moisture level               |
| Temperature Sensor   | Measures temperature                       |
| Humidity Sensor      | Measures humidity                          |
| Relay Module         | Controls the irrigation pump               |
| Water Pump           | Supplies water to the plant                |
| Power Supply         | Provides power to the system               |
| Connecting Wires     | Circuit connections                        |

## Software and Technologies

* Embedded C / Arduino C++
* Arduino IDE
* ESP32 / ESP8266
* IoT Cloud Platform
* IoT Dashboard
* Serial Monitor
* Wi-Fi Communication

## System Architecture

```text
          ┌─────────────────────┐
          │   Soil Moisture     │
          │      Sensor         │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │ Temperature &       │
          │ Humidity Sensors    │
          └──────────┬──────────┘
                     │
                     ▼
             ┌───────────────┐
             │ ESP32/ESP8266  │
             │  Microcontroller│
             └───────┬───────┘
                     │
             Wi-Fi / Internet
                     │
                     ▼
             ┌───────────────┐
             │  IoT Cloud     │
             │    Platform    │
             └───────┬───────┘
                     │
                     ▼
             ┌───────────────┐
             │   Dashboard    │
             │ Real-Time Data │
             └───────────────┘

                     │
                     │ Automation Logic
                     ▼
             ┌───────────────┐
             │ Relay Module   │
             └───────┬───────┘
                     │
                     ▼
             ┌───────────────┐
             │  Water Pump    │
             └───────────────┘
```

## Working Principle

1. The soil moisture sensor measures the moisture level of the soil.
2. The temperature sensor measures the surrounding temperature.
3. The humidity sensor measures environmental humidity.
4. The ESP32/ESP8266 reads the sensor values.
5. The microcontroller processes the sensor readings.
6. The sensor data is transmitted to the IoT cloud platform using Wi-Fi.
7. The dashboard displays the sensor readings in real time.
8. The soil moisture value is compared with a predefined threshold.
9. If the soil becomes sufficiently dry, the controller activates the relay.
10. The relay turns ON the water pump.
11. When the soil moisture reaches the required level, the pump is turned OFF.
12. The sensor values and irrigation status are continuously monitored.

## Irrigation Automation Logic

```text
        Read Soil Moisture
                │
                ▼
       Compare with Threshold
                │
        ┌───────┴────────┐
        │                │
   Soil is Dry      Soil is Wet
        │                │
        ▼                ▼
   Relay ON          Relay OFF
        │                │
        ▼                ▼
   Pump ON           Pump OFF
```

### Example Logic

```text
IF soil moisture < threshold
       → Relay ON
       → Water Pump ON

ELSE
       → Relay OFF
       → Water Pump OFF
```

The exact threshold depends on the sensor used and should be calibrated during testing.

## IoT Dashboard

The IoT dashboard provides real-time monitoring of the agricultural system.

The dashboard can display:

* Soil Moisture
* Temperature
* Humidity
* Irrigation / Relay Status
* Water Pump Status

### Dashboard Screenshot

![Smart Agriculture Dashboard](dashboard/dashboard_screenshot.png)

> Add the actual dashboard screenshot to the `dashboard` folder and update the filename if necessary.

## Circuit Diagram

The complete smart agriculture circuit consists of the microcontroller, soil moisture sensor, temperature/humidity sensor, relay module, and water pump.

![Smart Agriculture Circuit](circuit/smart_agriculture_circuit.png)

## Sensor Monitoring

The system continuously collects sensor readings and displays them through the Serial Monitor and IoT dashboard.

Example:

```text
Soil Moisture: 42%
Temperature: 25.4 °C
Humidity: 61.0 %
Irrigation: OFF
Pump: OFF
```

When the soil becomes dry:

```text
Soil Moisture: 18%
Temperature: 26.1 °C
Humidity: 57.0 %
Irrigation: ON
Pump: ON
```

## Data Analysis

Sensor readings can be analyzed to understand the relationship between soil moisture and irrigation requirements.

The following parameters can be analyzed:

| Parameter         | Purpose                           |
| ----------------- | --------------------------------- |
| Soil Moisture     | Determines irrigation requirement |
| Temperature       | Monitors environmental conditions |
| Humidity          | Monitors surrounding moisture     |
| Irrigation Status | Shows whether watering is active  |
| Pump Status       | Shows water pump operation        |

The collected data can be represented using tables or graphs to identify changes in soil and environmental conditions.

## Communication

The ESP32/ESP8266 communicates with the IoT cloud platform using Wi-Fi.

```text
Sensors
   ↓
ESP32 / ESP8266
   ↓
Wi-Fi
   ↓
IoT Cloud Platform
   ↓
Dashboard
```

The communication system is tested by verifying whether sensor readings from the microcontroller are correctly received and displayed on the IoT dashboard.

## Testing

The system is tested in multiple stages:

### 1. Sensor Testing

* Verify soil moisture sensor readings.
* Verify temperature readings.
* Verify humidity readings.

### 2. Communication Testing

* Verify ESP32/ESP8266 Wi-Fi connection.
* Verify data transmission to the cloud platform.
* Verify dashboard updates.

### 3. Automation Testing

* Simulate dry soil conditions.
* Check whether the relay turns ON.
* Verify that the water pump turns ON.
* Increase soil moisture.
* Verify that the relay and pump turn OFF.

### 4. System Integration Testing

All sensors, controller, cloud platform, dashboard, relay, and pump are tested together to verify complete system operation.

## Testing Results

| Test Case            | Expected Result              | Status |
| -------------------- | ---------------------------- | ------ |
| Soil moisture sensor | Correct moisture reading     | PASS   |
| Temperature sensor   | Correct temperature reading  | PASS   |
| Humidity sensor      | Correct humidity reading     | PASS   |
| Wi-Fi connection     | Device connects successfully | PASS   |
| Cloud communication  | Data reaches dashboard       | PASS   |
| Dashboard            | Real-time values displayed   | PASS   |
| Dry soil condition   | Pump turns ON                | PASS   |
| Wet soil condition   | Pump turns OFF               | PASS   |
| Complete automation  | System operates correctly    | PASS   |

## Screenshots

### Sensor Readings

![Sensor Readings](screenshots/sensor_readings.png)

### Irrigation ON

![Irrigation ON](screenshots/irrigation_on.png)

### Irrigation OFF

![Irrigation OFF](screenshots/irrigation_off.png)

### Dashboard

![Dashboard](dashboard/dashboard_screenshot.png)

## Project Folder Structure

```text
Cognevance_IoT_SmartAgriculture/
│
├── README.md
│
├── src/
│   └── smart_agriculture.ino
│
├── circuit/
│   └── smart_agriculture_circuit.png
│
├── dashboard/
│   └── dashboard_screenshot.png
│
├── screenshots/
│   ├── sensor_readings.png
│   ├── irrigation_on.png
│   └── irrigation_off.png
│
├── testing/
│   └── testing_report.md
│
└── documentation/
    └── project_documentation.pdf
```

## Expected Outputs

The completed system should provide:

* Real-time soil moisture monitoring
* Real-time temperature monitoring
* Real-time humidity monitoring
* IoT cloud data transmission
* Real-time dashboard visualization
* Automatic irrigation control
* Sensor data analysis
* Testing and validation results

## Advantages

* Reduces manual monitoring
* Helps optimize water usage
* Provides real-time agricultural data
* Enables remote monitoring
* Supports automatic irrigation
* Provides a scalable IoT-based solution

## Limitations

* Sensor accuracy may vary depending on calibration.
* Wi-Fi connectivity is required for cloud monitoring.
* Soil moisture thresholds need to be calibrated for different soil and crop conditions.
* The system depends on reliable power for the controller and irrigation pump.

## Future Scope

The system can be further improved by adding:

* Multiple soil moisture sensors
* Multiple irrigation zones
* Weather API integration
* Rain detection
* Water-level monitoring
* Mobile notifications
* Data logging and historical analytics
* Machine-learning-based irrigation prediction
* Solar-powered operation
* Crop-specific irrigation recommendations

## Conclusion

The IoT-Based Smart Agriculture Monitoring System demonstrates how embedded systems and IoT technologies can be used for real-time agricultural monitoring and automated irrigation.

The system integrates soil moisture, temperature, and humidity sensing with an ESP32/ESP8266 and cloud-based monitoring. Based on soil moisture conditions, the irrigation system can automatically control the water pump, helping reduce manual effort and support efficient water management.
