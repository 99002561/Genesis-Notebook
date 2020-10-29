
# Layers of Embedded System
1. Application
2. Middle ware and user defined API
3. OS + Drivers
	* OS is used for Scheduling and timing events
	* OS based systems are for major managements(Optional)
	* Drivers contains pointers and structures
4. Physical Hardware


# Beagle Bone Black Board
It’s an open source h/w, s/w platform
It a single piece of circuit board, comprises most of the personal Computer hardware/software components

![pin layout](black_hardware_details.png)

## Feature
* Processor(SOC): AM335x 1GHz ARM® Cortex-A8
* 512MB DDR3 RAM
* 4GB 8-bit eMMC on-board flash storage
* 3D graphics accelerator
* NEON floating-point accelerator
* 2x PRU 32-bit microcontrollers
* Connectivity
    * USB client for power & communications
    * USB host
    * Ethernet
    * HDMI
    * 2x 46 pin headers

Other BeagleBone derivatives »
Software Compatibility

    Debian
    Android
    Ubuntu
    Cloud9 IDE on Node.js w/ BoneScript library
    plus much more




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




# Quick Start
	How to Communicate with Beagle bone black using serial debug interface

## Hardware
1. Beagle Bone Black
2. USB to TTL serial cable
3. Mini usb Cable
* https://beagleboard.org/getting-started 

## Minicom
	To serial communicate with BBB board
### Installation
1. Install Serial Terminal 
(Serial Port Communication program)
1. Update the package index
sudo apt-get update
2. Install minicom deb package
sudo apt-get install minicom

* https://help.ubuntu.com/community/Minicom

### Settings
1. Connect USB to TTl 
	Connect the USB side of the TTL cable to your computer
	Connect the wires to J1 headers on your BeagleBone Black
	Black wire to Pin 1
	Green wire to Pin 4
	White wire to Pin 5

2. Find Port Details
	* dmesg | grep tty
	[ 1977.652735] usb 1-1.4: pl2303 converter now attached to ttyUSB0
	* ls /dev/tty*

3. minicom settings
	1. sudo minicom -s
	2. serial port setup
		A. Serial Device : /dev/ttyUSB0
		E. bps - 115200 8N1
		F- Hardware Flow Control: No
		G- Software Flow Control: No
	3. save setup as dfl
	4. exit by esc


## Gparted

1. Update the package index
	sudo apt-get update
	sudo apt-get upgrade
2. Install software to make pendrive bootable 
	sudo apt-get install gparted

### partition
boot - fat16
Rootfs(ext3/ext4)



sudo cp -r * /media/user/ROOTFS
sync


## Linux Booting in BBB board
1. RBl(ROM bootloader)
	stack setup
	watchdog timer 1
	system clock configuration using pll
	loads and executes SPL/MLO
2. MLO
	loads uboot.img into dram 
3. uBoot(runs uboot.img)
	initialize peripherals
	loads kImage

rbl + mlo(bootloader - process of loading boot files)
uboot.img(booting - process of loading kernel to main memory)
kImage

# Day 3 Notes

## dtb file
