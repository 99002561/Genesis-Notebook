# 0. Layers of Embedded System
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

## 1. Part details
* SOC(Systems on chips)
	* part number is U5
	* XAM3359A
* Embedded MMC (eMMC) part No: is U13.
* DDR3 part no : is U12
* UART part no: J1
	8N1 no parity and one stop bit,115200 baudrate
* Boot loader part no : s2
* Power Button part no: is s3 
* Mini port (power):part no: P6
* Memory card slot part No: P10
* MMC0 is connected to microSD card
* MMC1 is Connected to eMMC 
* DC Adapter:1A current and 5V voltage.
	
## 2. AM355x SOC by TI
* SOC is: AM3358BZCZ100 on REV ‘C’ BBB Board
* [Datasheet](AM335x_data_sheet.pdf)
* [Manual](AM335x_manual.pdf)

![Features](ARM335x_features.png)

## 3. DDR3
* Board comes with  external Dynamic RAM memory(SDRAM) of 512MB DDR3
* During booting the boot images will get loaded to this RAM from other memories and will execute from here.

## 4. Communication Setup
Minicom is used as serial communicate program with BBB board using serial debug interface
* https://help.ubuntu.com/community/Minicom

### 1. Installations
1. Update the package index
	`sudo apt-get update`
2. Install minicom deb package 
	`sudo apt-get install minicom`

### 2. Settings
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

## 5. Linux Booting

### 1. Booting Options
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

#### Boot Order
* when S2 Released (SYSBOOT[4:0] = 11100)
	MMC1 (eMMC)
	MMC0 (SD card)
	UART0
	USB0

* when S2 pressed (SYSBOOT[4:0] = 11000)
	SPI0
	MMC0 (SD card)
	USB0
	UART0

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

#### UART Port
* used on UART0(115200 8n1)
* Any serial communication program will work
* uses x-modem protocol to load the boot image
	1. `loadx DRAMaddress` optional only for specific address loading
	2. `(cntrl + A) + S`
	3. select `x-modem`
	4. select file by navigation
		double space to go in and single space + enter to select


### 2. Booting Sequence

![boot sequence](bootSequence.jpg)

1. ROM bootloader(RBL)
	1. stack setup
	2. watchdog timer configuration(3minutes)
	3. system clock configuration using pll
	4. Booting
		1. checks boot devices list based on SYSBOOT reg
		2. configure booting device
		3. search & loads SPL/MLO to internal SOC Ram
		4. executes SPL/MLO from internal SOC Ram

2. Memory Loader/Secondary program loader(MLO/SPL) Job
	rbl + mlo(bootloader - process of loading boot files)
	This is also known as X-loader
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

### 3. Booting Setup

#### u-boot area commands
	printenv
	iminfo
	help
	load
	setenv
	loadx
	loady

#### 1. SD Card
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
	5. Apply all operations
	6. set boot flag for BOOT partition

2. copy Image files to BOOT partition
	1. MLO
	2. u-boot.img
	3. uEnv.txr

3. Copy ROOT files to ROOTFS partition
	1. open ROOT files directory in terminal
	2. `sudo cp -r * /media/user/ROOTFS`

4. Insert SD card to BBB board and 

5. connect serial ttl cable to pc and open terminal -> run minicom

6. boot the board from SD card using S2 switch

7. [Observe booting logs](bootingLog.txt)

 Auto Booting procedure
make serial interface with pc
Make ur BBB to enter from SD card

observe response from BBB in ur serial terminal

* u-boot.img
 uEnv.txt
 dtb file
 bootstrap
 kernel image
 U-boot area commands


Day 3 Notes

 dtc file

In embedded system the source code is converted to hex file 
and placed in the memory
peripheral drivers are hard loaded

 uEnv.txt(y-modem)

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


#### 2. UART Port
1. enter into uart boot mode
	1. connect serial ttl cable
	2. press s2 and power by dc adapter
2. Load TI Images to DRAM [Images link](BBB_images/serial-boot.zip)
	1. open terminal and run `sudo minicom` 
		Response: `CCCCCCCCCCC`
	2. load MLO(u-boot-spl.bin) using x-modem `(cntrl+a)+s`
	3. load u-boot.img using x-modem
	4. enter space to enter into U-boot area
	5. load uImage at 0x82000000  `loadx 0x82000000`
	6. load .dtb file art 0x88000000 `loadx 0x88000000`
	7. load intra file system at 0x88080000`loadx 0x88080000` 
3. set bootargs(for logs)
	`setenv bootargs console=ttyO0,115200 root=/dev/ram0 rw initrd=0x8808000`
4. boot with memory address
	`bootm ${kernelImage_addr} ${inrafrms_addr} ${dtb_addr}`
	`bootm 0x82000000 0x88080000 0x88000000`

* [Logs](BBB_logs/UARTlog.txt)

## 6. Cross tool-chain for linux host(PC)

### Installation
Download arm cross toolchain for your Host machine
[gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabihf.tar.xz](https://releases.linaro.org/components/toolchain/binaries/latest-5/latest-5/arm-linux-gnueabihf/)
or 

sudo apt-get install libncurses5-dev libncursesw5-dev
sudo apt-get install libncurses5-dev libncursesw5-dev
sudo apt-get install -y u-boot-tools
sudo apt install lzop


### Settings
export  path of the cross compilation toolchain
1. open bashrc `code ~/.bashrc` 
2. update path in .bashrc file 
	`export PATH=/home/user/Documents/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabihf/bin:$PATH`
	or 
	`export PATH=$PATH:/home/user/Documents/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabihf/bin`
3. reload bashrc `source /home/user/.bashrc`
4. `arm` and couples of times TAB button to see the files


# Todo
* Day3 content update
* qemu(Emulator)
* booting from TFTT protocol
* Yammer preRead
* Menu Configurations
* Compiling u boot Image
* alias names for particular file
* busybox

# Concepts
* Basics of Beagle board
* Basics of ARM
* Boot sequence
* autoBoot from SD card 
* boot from SD card 
	* user U-BOOT commands	
* Uboot Raw file explore
* Booting from UART
* Compiling uBoot.img
	* Change Default Configurations(Change autoboot ti)
* Compiling Linux kernel for BBB
	* Change kernel logs like logo

## Reference links
[Logs](https://johnvidler.co.uk/linux-journal/LJ/234/11551.html)
[u-boot.img raw c files](ftp://ftp.denx.de/pub/u-boot/)
[Beagle board Github](https://github.com/beagleboard/linux)
[Compiler Tools](https://releases.linaro.org/components/toolchain/gcc-linaro/latest-5/)