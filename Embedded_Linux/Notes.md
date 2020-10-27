Topics
Layers of Embedded System
1. Application
2. Middle ware and user defined API
3. OS + Drivers
* OS is used for Scheduling and timing events
* OS based systems are for major managements
* Drivers contains pointers and structures
4. Physical Hardware

Beagle Bone Black board
	Beagle Bone Black is a low-cost, community-supported development platform for developers and hobbyists. Boot Linux in under 10 seconds and get started on development in less than 5 minutes with just a single USB cable.

1. Features
2.  Specification
	* Recommended 5v @2A for DC power Adapter
3. Pin Diagram
4. Board Details: 
1.AD335x - 
	Soc No: XAM3359A		Part No. U5
2.eMMC
	Part No:U13
3. DDR3				U12
4. UART 				j1
	boot loader s2
power button s3
Mini USB port(p6)
Used for power and data transfer
500ma which is used to power up the internal operations and require extra for peripheral

Recommended DC Adapter
Mini HDMI Connector


## beagleboard
* Dbn boards or angstrom boards(v12.12,kernel-3.8.13)




Power up board
Ack logs from the board
ebian
3. temppwd
4. 

MMC0 --> Microsd card
MMC1 --> eMMC Memory - u13



How to Communicate with Beagle bone black
# Quick Start

## Hardware
1. Beagle Bone Black
2. USB to TTL serial cable
3. Mini usb Cable
* https://beagleboard.org/getting-started 

## Installation
1. Install Serial Terminal 
(Serial Port Communication program)
1. Update the package index
sudo apt-get update
2. Install minicom deb package
sudo apt-get install minicom

* https://help.ubuntu.com/community/Minicom

## Settings
1. Find Port Details
dmesg | grep tty
* Response:
[ 0.000000] console [tty0] enabled
[ 5.065029] usb 4-3: pl2303 converter now attached to ttyUSB0

2. minicom settings
1. sudo minicom -s
2. serial port setup
A. Serial Device : /dev/ttyUSB0
E. bps - 115200 8N1
F- Hardware Flow Control: No
G- Software Flow Control: No
3. save setup as default
4. exit

ls /dev/tty*
Connect the USB side of the TTL cable to your computer
Connect the wires to J1 headers on your BeagleBone Black
Black wire to Pin 1
Green wire to Pin 4
White wire to Pin 5
ls /dev/tty*

