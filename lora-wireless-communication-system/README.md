# LoRa-Based Wireless Communication System

An internship project focused on developing and testing a LoRa-based
wireless communication system, analyzing key RF parameters for
reliable long-range IoT communication.

> Internship at **IdeaBytes Software Pvt Ltd, Hyderabad**
> Role: Embedded IoT Intern (October 2025 - Present)

## Overview
Developed and tested a LoRa Point-to-Point (P2P) communication system
using the LoRa Wio-E5 module. The project involved analyzing signal
quality parameters and tuning communication settings for reliable
long-range data transmission between nodes.

## Features
- LoRa P2P communication between transmitter and receiver nodes
- Long-range wireless transmission
- Low power consumption analysis
- Real-time RSSI and SNR monitoring
- Parameter tuning for reliable communication

## System Architecture
---------------------- LoRa(P2P) ----------------------
|  Transmitter TX  |  ------------->  |  Receiver RX  |
-------------------------------------------------------

## Key Parameters Analyzed
- **RSSI** — Received Signal Strength Indicator
- **SNR** — Signal-to-Noise Ratio
- **Transmission Timing** — Communication latency evaluation
- **Power Consumption** — Optimizing for low-power IoT operation
- **Parameter Tuning** — Adjusting settings for reliable communication

## Working Principle
1. Transmitter node sends data packets periodically
2. Receiver node continuously listens for incoming packets
3. On receiving a packet, RSSI and SNR values are analyzed
4. Parameters are tuned based on signal quality observations

## Packet Frame Structure

### Uplink Frame [ DevAddr(4) | Timestamp(4) | Temp(2) | Humi(2) | BatVolt(2) | BatPercent(1) | CRC(2) ]

| Field | Size | Description |
|---|---|---|
| DevAddr | 4 bytes | Unique device address identifying the node |
| Timestamp | 4 bytes | Periodic packet timing using STM32 RTC |
| Temp | 2 bytes | Temperature sensor data |
| Humi | 2 bytes | Humidity sensor data |
| BatVolt | 2 bytes | Battery voltage in millivolts via ADC on PB4 |
| BatPercent | 1 byte | Battery percentage for state management |
| CRC | 2 bytes | Cyclic redundancy check for data integrity |

### Downlink Frame
| Field | Size | Description |
|---|---|---|
| MHDR | 1 byte | Message header indicating message type |
| DevAddr | 4 bytes | Target device address |
| RSSI | 2 bytes | Link quality indicator for range determination |
| Flags | 1 byte | Control flags |
| Count | 1 byte | Packet counter |
| CRC | 2 bytes | Data integrity check |

> 🔋 Battery management: transmission stops below cutoff voltage
> and device enters permanent low-power mode.

## 🛠️ Technologies Used
- Embedded C
- STM32CubeIDE
- LoRa P2P Communication
- SPI Communication
- Wireless Embedded Systems

## About
**Company:** IdeaBytes Software Pvt Ltd, Hyderabad
**Role:** Embedded IoT Intern (October 2025 - Present)

> Note: Source code is proprietary and not included in this repository.
