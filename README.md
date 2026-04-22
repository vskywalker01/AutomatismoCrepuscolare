# Solar-Switcher
This repository contians the source code and pcb design for an automatic load switcher that controls high power consumption devices in base of the energy that a photovoltaic system can currently generate.

## How it works 
The switcher contains four different relays controlled by an Arduino Pro Mini that collects periodically samples from a photo-resistor and converts them into an estimated power (the power that the inverter should generate at the time). 
In base of a fixed priority order, the controller turns on and off the relays so that the overall consumptions fits into the estimated power.

<img width="322" height="381" align="center" alt="schematic" src="https://github.com/user-attachments/assets/2def72c3-0a4f-4ce9-832c-5d227f79d7b1" />

## Hardware 
The folder [*pcb*](pcb/) contains the Kicad project of the PCB. the required components are shown in the following table. 

| Name  | Value | Quantity |
| ------------- | ------------- | ------------- |
| Arduino Pro mini   |              | x1 |
| LCD Display 16x2   |              | x1 |
| 74LS595            |              | x1 | 
| Relay              | 12V to 24V   | x4 |
| LM7805             |              | x1 | 
| BC237              |              |    |

- One Arduino Pro Mini with AtMega328p. 
- Four 12V/24V relays
- One 16x2 LCD display, 
- One 74ls595 shift register
- One photo-resistor
- Three buttons
- 
