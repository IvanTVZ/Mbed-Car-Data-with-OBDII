# Mbed-Car-Data-with-OBDII

# About
On-board diagnostics (OBD) is a term referring to a vehicle's self-diagnostic and reporting capability.
OBD-II PIDs (On-board diagnostics Parameter IDs) are codes used to request data from a vehicle, used as a diagnostic tool.
The PID query and response occurs on the vehicle's CAN bus. Standard OBD requests and responses use functional addresses.

More information about OBD II can be found at the [wiki page](https://en.wikipedia.org/wiki/On-board_diagnostics).
More information about OBD II PIDs can be found at the [wiki page](https://en.wikipedia.org/wiki/OBD-II_PIDs).

## Project idea
In this project the goal is to create a device capable of getting and processing car data through the OBD II port with the use of OBD II PIDs.

## Project status
- [x] Programming
- [x] Breadboard prototype
- [x] Schematic
- [x] Tested on car
- [ ] PCB
- [ ] 3D enclosure design

## Main features
- Based on LPC1768 microcontroller
- Getting data from car with OBD II
- LCD Menu
- PC serial communication for debugging

# Documentation
## Sample debug output
The program was tested on the following car: Mazda 3 2008, and the following is a sample query and response:

CAN TX Message - Transmit Engine Speed
<br />Message ID: 0x7e0
<br />Message Data [0]: 0x02
<br />Message Data [1]: 0x01
<br />Message Data [2]: 0x0c
<br />Message Data [3]: 0
<br />Message Data [4]: 0
<br />Message Data [5]: 0
<br />Message Data [6]: 0
<br />Message Data [7]: 0

<br />CAN RX Message - Received Engine Speed
<br />Message ID: 7e8
<br />Message Length: 8
<br />Message Data [0]: 4
<br />Message Data [1]: 41
<br />Message Data [2]: c
<br />Message Data [3]: 2a
<br />Message Data [4]: 38
<br />Message Data [5]: 0
<br />Message Data [6]: 0
<br />Message Data [7]: 0
<br />Engine Speed: 2702

## Schematic
<p align="center">
  <img width="1024" src="https://github.com/IvanTVZ/Mbed-Car-Data-with-OBDII/assets/148143766/187dbeef-3748-4db1-a85b-329bd59ed8fd">
</p>

## Images
<p align="center">
  <img width="1024" src="https://github.com/IvanTVZ/Mbed-Car-Data-with-OBDII/assets/148143766/7d143a98-b1c5-4a33-a2eb-0cc391fe831c">
</p>

<p align="center">
  <img width="1024" src="https://github.com/IvanTVZ/Mbed-Car-Data-with-OBDII/assets/148143766/485f85dd-3ac5-4c91-9e9d-10bb14362af3">
</p>
