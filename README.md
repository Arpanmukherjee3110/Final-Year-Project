## Final Year Project

An intelligent DC-DC Buck Converter developed using the **Texas Instruments TMS320F280025C C2000 Microcontroller** featuring closed-loop voltage regulation, OLED-based user interface, UART communication with ESP32, and support for AI-based predictive maintenance of power electronic components.

---

## Project Overview

This project implements a digitally controlled Buck Converter capable of maintaining a desired output voltage using feedback control. The converter is controlled entirely by the **TMS320F280025C**, while an **ESP32** is used for data collection and communication with a laptop for future AI-based health monitoring.

The project is divided into two major sections:

1. Real-time Digital Power Converter Control
2. AI-assisted Predictive Maintenance

The firmware included in this repository implements the complete embedded control system running on the F280025C.

---

## Features

- Closed-loop Buck Converter control
- High-frequency PWM generation using ePWM
- ADC-based voltage measurement
- Rotary Encoder based output voltage selection
- OLED Display (SSD1306)
- UART communication with ESP32
- Fault detection support
- Modular code structure
- Easily expandable for current control and PID implementation
- Designed for predictive maintenance integration

---

## Hardware Used

| Component | Description |
|-----------|-------------|
| TI LaunchXL-F280025C | Main Controller |
| Buck Converter Power Stage | DC-DC Converter |
| IRFZ44N MOSFET | Power Switch |
| Gate Driver | MOSFET Driver Circuit |
| SSD1306 OLED | User Interface |
| Rotary Encoder | Output Voltage Selection |
| ESP32 | UART Data Logger |
| Voltage Divider | Output Voltage Feedback |
| Current Sensor | Current Measurement |

---


## Software Used

- Code Composer Studio (CCS)
- C2000Ware DriverLib
- C Language
- TI C2000 Compiler


## System Architecture

```
      +----------------+
      | Rotary Encoder |
      +-------+--------+
              |
              v

      +----------------+
      |   F280025C     |
      |                |
      | ADC            |
      | PWM            |
      | UART           |
      +---+--------+---+
          |        |
          |        |
          |        +-------------> ESP32
          |                         |
          |                         |
          |                     Laptop
          |
          v

     Gate Driver
          |
          v

      Buck Converter

          |
          v

 Output Voltage Feedback
          |
          |
          +-------> ADC

OLED Display
     ^
     |
 I2C Interface
```

---

## Firmware Workflow

1. Initialize Device
2. Configure System Clock
3. Initialize GPIO
4. Configure ADC
5. Configure ePWM
6. Initialize UART
7. Initialize OLED
8. Initialize Rotary Encoder
9. Enable Interrupts
10. Start PWM
11. Read Output Voltage
12. Compute Control Output
13. Update PWM Duty Cycle
14. Send Data to ESP32
15. Update OLED
16. Repeat

---

## Control Strategy

The Buck Converter operates in a closed-loop configuration.

### Feedback

- Output voltage is sampled using ADC.
- Voltage divider scales converter output.
- ADC converts analog voltage into digital value.

### Controller

Current implementation supports:

- Proportional Control
- PI Control (can be enabled)
- Easily extendable to PID

Controller computes

```
Error = Vref - Vout
```

and updates PWM duty cycle accordingly.

---

## UART Communication

The controller periodically transmits

- Input Voltage
- Output Voltage
- PWM Duty Cycle
- System Status
- Fault Flags

to the ESP32.

The ESP32 forwards the data to a laptop for future AI analysis.

---

## OLED Display

The SSD1306 OLED displays

- Input Voltage
- Output Voltage
- Selected Voltage
- Duty Cycle
- Converter Status
- Fault Messages

---

## Output Voltage Selection

A rotary encoder allows the user to choose different output voltage levels.

Example

```
12 V

15 V

18 V

20 V
```

The controller automatically regulates the converter to maintain the selected output.

---

## AI Predictive Maintenance (Future Scope)

The embedded controller is designed to support AI-based health monitoring.

The ESP32 continuously collects converter parameters and forwards them to a computer where machine learning models can estimate the health of

- MOSFET
- Capacitor
- Converter

using historical operating data.

Potential measurable features include

- Output Voltage Ripple
- Duty Cycle
- Temperature
- Switching Frequency
- Input Voltage
- Output Current
- ESR Estimation
- Capacitance Degradation

---

## Interrupts Used

- ADC Interrupt
- ePWM Interrupt
- Timer Interrupt (optional)
- UART Interrupt (optional)

---

## Build Instructions

1. Install Code Composer Studio.
2. Install the latest C2000Ware package.
3. Import the CCS project.
4. Select

```
LaunchXL-F280025C
```

5. Build the project.
6. Connect the LaunchPad.
7. Flash the firmware.
8. Open CCS Serial Monitor (optional).



---

## Acknowledgements

- Texas Instruments
- C2000Ware Driver Library
- ESP32 Community
- NASA Prognostics Center (for predictive maintenance datasets)
