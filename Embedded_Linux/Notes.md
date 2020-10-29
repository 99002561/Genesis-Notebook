# Layers of Embedded System
1. Application
2. Middle ware and user defined API
3. OS + Drivers
	* OS is used for Scheduling and timing events
	* OS based systems are for major managements(Optional)
	* Drivers contains pointers and structures
4. Physical Hardware

# Beagle Bone Black Board
* It’s an open source h/w, s/w platform
* It a single piece of circuit board, comprises most of the personal Computer hardware/software components
* Software Compatibility
    Debian
    Android
    Ubuntu
    Cloud9 IDE on Node.js w/ BoneScript library
* [Manual](BBB_Manual.pdf)
* [Schematic](BBB_Schematic.pdf)

![Features](BBB_features.jpg)

## AM355x SOC by TI
* SOC is: AM3358BZCZ100 on REV ‘C’ BBB Board
* [Datasheet](AM335x_data_sheet.pdf)
* [Manual](AM335x_manual.pdf)
![Features](ARM335x_features.png)

## DDR3
* Board comes with  external Dynamic RAM memory(SDRAM) of 512MB DDR3
* During booting the boot images will get loaded to this RAM from other memories and will execute from here.

## Communication Setup
Minicom is used as serial communicate program with BBB board using serial debug interface
* https://help.ubuntu.com/community/Minicom

### Installations
1. Update the package index
	`sudo apt-get update`
2. Install minicom deb package 
	`sudo apt-get install minicom`

### Settings
1. Connect USB to TTl 
	1. Connect the USB side of the TTL cable to your computer
	2. Connect the wires to J1 headers on your BeagleBone Black
		1. Black wire to Pin 1
		2. Green wire to Pin 4
		3. White wire to Pin 5

2. Find Port Details
	* `dmesg | grep tty`
	`[ 1977.652735] usb 1-1.4: pl2303 converter now attached to ttyUSB0`
	* `ls /dev/tty*`

3. minicom settings
	1. `sudo minicom -s`
	2. serial port setup
		A. Serial Device : /dev/ttyUSB0
		E. bps - 115200 8N1
		F- Hardware Flow Control: No
		G- Software Flow Control: No
	3. save setup as dfl
	4. exit by esc

## Linux Booting

### Boot Options
The AM335x SOC boots from the following sources
1) NAND Flash
2) NOR Flash (eXecute In place, XIP)
3) USB
4) eMMC
5) SD card
6) Ethernet
6) UART
7) SPI
That means, you can keep the boot images in any of the above memory or peripheral and you can able to boot this SOC.

#### eMMC Boot(MMC1)
* eMMC is connected over MMC1 interface, 
* This is the fastest boot mode possible, 
* This is the default boot mode. 
* As soon as you reset the board, the board start booting from loading the images stored in the eMMC.
* If no proper boot image is found in the eMMC, then Processor will automatically try to boot from the next device on the list.

#### SD boot(MMC0)
* sd card connector at MMC0 interface
* If the default (eMMC) boot mode fails, then it will try to boot from the SD card 
* If you press S2 and then apply the power, then 
	1. the board will try to boot from the SPI
	2. if nothing is connected to SPI, it will try to boot from the MMC0(SD card)
* we can use SD card boot to flash boot images on the eMMC
	1.  boot through sd card
	2. write new images to eMMC
	3. reset the board, so that your board can boot using new images stored in the eMMC.

#### Serial Port
In this mode, the ROM code of the SOC will try to download the boot images from the serial port

#### USB Port
* This is booting through usb stick!
* You would have booted your PC through the usb stick. What you do is, you restart the PC, then press bios button to put the PC in to bios mode, there you select boot form usb, right? so It is very similar, when you reset the board, you can make your board to boot from the USB stick.

### Booting stages
1. ROM bootloader(RBL)
	1. stack setup
	2. watchdog timer configuration(3minutes)
	3. system clock configuration using pll
	4. Booting
		1. checks boot devices list based on SYSBOOT pins
		2. configure booting device
		3. search & loads SPL/MLO to internal SOC Ram
		4. executes SPL/MLO from internal SOC Ram

2. Memory Loader/Secondary program loader(MLO/SPL) Job
	rbl + mlo(bootloader - process of loading boot files)
	1. UART Initialization for printing debug messages
	2. ppl modification to desired value
	3. Configures communication between the SOC and DRAM
	4. search and Load u-boot.img to DRAM
	5. runs u-boot.img

3. u-boot jobs
	booting - process of loading kernel to main memory
	1. initialize peripherals 
	2. loads Linux kernel Image(ROOTFS/boot/uBoot) to DRAM
	3. Passing boot arguments

## Booting setup
1. Make SD Card Bootable
	1. Install Gparted
		1. Update the package index
			`sudo apt-get update`
			`sudo apt-get upgrade`
		2. Install software to make pendrive bootable 
			`sudo apt-get install gparted`
	2. Format SD Card
	3. Create New partition for boot files
		- Label: BOOT
		- file system: fat16 (minimum 2gb)
	4. Create New Partition for linux root files
		- Label: ROOTFS
		- file system: ext3/ext4 
	5. 

2. Download Image files
explain image files

3. Auto Booting procedure
make serial interface with pc
Make ur BBB to enter from SD card

observe response from BBB in ur serial terminal

## u-boot.img
### uEnv.txt
## dtb file
## bootstrap
## kernel image






Rootfs(ext3/ext4)


`sudo cp -r * /media/user/ROOTFS`
sync




# Day 3 Notes

## dtc file
In embedded system the source code is converted to hex file 
and placed in the memory
peripheral drivers are hard loaded

## uEnv.txt

console=ttyO0,115200n8
ipaddr=192.168.7.2
serverip=192.168.7.1
loadaddr=0x82000000
fdtaddr=0x88000000


1. Write Commands
	1. Load uImage file
		loadfromsd=load mmc 0:2 ${loadaddr}  /boot/uImage
	2. Load .dtb file
		load mmc 0:2 ${fdtaddr} /boot/am335x-boneblack.dtb
	3.  get Logs
		linuxbootargs=setenv bootargs console=${console} root=/dev/mmcblk0p2 rw

2. Run Commands
	uenvcmd=setenv autoload no; 
	run loadfromsd;
	run linuxbootargs; 
	bootm ${loadaddr} - ${fdtaddr}


loady



# Todo
* qemu(Emulator)