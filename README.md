# Solar-Switcher
This repository contains *source code* and *PCB design* for an automatic load switcher that controls high power consumption devices in base of the energy that a photovoltaic system can currently generate.

## How it works 
The switcher contains four different relays controlled by an Arduino Pro Mini that collects periodically samples from a photo-resistor aligned with the panels and converts them into an estimated power (the power that the inverter should be capable to generate at the time). 
<p align="center">
<img width="322" height="381" align="middle" alt="schematic" src="https://github.com/user-attachments/assets/2def72c3-0a4f-4ce9-832c-5d227f79d7b1" />
</p>

In base of a fixed priority order, the controller turns on and off the relays so that the overall consumptions fits into the estimated power.

## Software 
The software provide a simple user interface controllable by only three buttons (PLUS, MINUS and CONTROL) which contains a general visualization of the relays with dedicated pages for their details and a settings menu, for editing the options in real time. 

> [!NOTE]
> All the settings are automatically saved into the internal EEPROM of the Arduino microcontroller. 

> [!IMPORTANT]
> Currently, only Italian is supported as display language (English support may follow in next updates).

### Sensor conversion and calibration 
The photoresistor used for sampling the light intensity is used for estimating the power that the inverter system can generate on the fly. For this purpose, the analog pin A0 reads constantly the raw values and converts them using a power function defined as 

<h2 align="center">$(\frac{raw - \gamma}{\alpha})^\beta$</h2> 

The three parameters should be tuned by the user in the settings menu in order to assure that the power estimated follows the real one provided by the inverter. 

A good way to do that is to collect known points between *light* value and *power* consumption from the display and tune the parameters on Geogebra so that the curve pass near them. 

<p align="center">
<img width="1822" height="869" alt="image" src="https://github.com/user-attachments/assets/8610cb9d-342e-4d31-9039-65e7f437c37c" />
</p>

In my case, for example, knowing that a pump consumes 2kW and a boiler 1.2kW, i obtained that the inverter can handle:
- **pump and boiler** (3,2kW) when the light value is greater or equal to *848*
- **pump until** (2kW) the light value is greater or equal to *800*

### Relay priority system 
The four relays are organined in a fixed priority order where the first one has the highest priority and the last one has the lowest priority. 

Using the power function, the solar switcher tries to turn on the highest amount of relays in order to fit into the estimated power obtained. This means that, as long as a relay with higher priority is turned on, the relays with lower priority will have less available energy. 

> [!NOTE]
> The user can choose to exlude a certain relay from the priority order in the settings using a mask that keeps it deactivated. 

### Source code 
The folder [*software*](software/) folder contains the commented source code of the Solar switcher ready to be flashed to the arduino board. A simple makefile downloads the required libraries, compiles the program and flash the microcontroller automatically using `arduino-cli`:

```
make run PORT=/dev/ttyUSB0 
```

## Hardware 
The folder [*pcb*](pcb/) contains the Kicad project, the [schematic](pcb/pdf/schematic.pdf),the specular [copper layer](pcb/pdf/output.pdf) ready for the press-n-peel and the [silkscreen](pcb/pdf/board.pdf). 

The required components are shown in the following table. 

| Name  | Quantity |
| ---------------------- | -- |
| Arduino Pro mini       | x1 |
| LCD Display 16x2       | x1 |
| Button                 | x3 |
| Relay 12 to 24V        | x4 |
| 74LS595                | x1 | 
| LM7805                 | x1 | 
| BC237                  | x4 |
| 1k Ohm resistor        | x8 | 
| 10k Ohm resistor       | x1 | 
| 510 Ohm resistor       | x4 | 
| 10k Ohm trimmer        | x1 |
| 2.2k trimmer           | x1 | 
| LED                    | x4 |
| PC817                  | x4 | 
| 1N4148                 | x4 | 
| 100nf capacitor        | x4 | 
| 200mf capacitor        | x1 | 

