# CH552E MacroPad mini
The MacroPad mini is a highly versatile keyboard extension that boasts three programmable keys. These keys can be configured to execute a vast array of actions, including the triggering of specific key combinations and sequences. Additionally, the firmware used to operate the MacroPad can be easily modified to suit the needs of the user.

Each button on the MacroPad is also equipped with an addressable LED (NeoPixel), which can be programmed in the same way as the keys. This provides the user with an additional level of customization, allowing them to assign specific colors or patterns to each key, making them easier to identify at a glance.

Connecting the MacroPad to a PC is a breeze, as it simply plugs in via USB. Once connected, the MacroPad is immediately recognized by the PC as an HID multimedia keyboard, meaning that it requires no special drivers to function. This makes the MacroPad an incredibly user-friendly and accessible option for those looking to expand their keyboard capabilities.

![Macropad_mini_pic1.jpg](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_pic1.jpg)

# Hardware
## Schematic
![Macropad_mini_wiring.png](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_wiring.png)

## CH552E 8-bit USB Device Microcontroller
The CH552E is a low-cost, enhanced E8051 core microcontroller compatible with the MCS51 instruction set. It has an integrated USB 2.0 controller with full-speed data transfer (12 Mbit/s) and supports up to 64 byte data packets with integrated FIFO and direct memory access (DMA). The CH552E has a factory built-in bootloader so firmware can be uploaded directly via USB without the need for an additional programming device.

![Macropad_mini_pic3.jpg](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_pic3.jpg)
![Macropad_mini_pic2.jpg](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_pic2.jpg)

# Compiling and Installing Firmware
## Preparing the CH55x Bootloader
### Installing Drivers for the CH55x Bootloader
On Linux you do not need to install a driver. However, by default Linux will not expose enough permission to upload your code with the USB bootloader. In order to fix this, open a terminal and run the following commands:

```
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="4348", ATTR{idProduct}=="55e0", MODE="666"' | sudo tee /etc/udev/rules.d/99-ch55x.rules
sudo service udev restart
```

On Windows you will need the [Zadig tool](https://zadig.akeo.ie/) to install the correct driver. Click "Options" and "List All Devices" to select the USB module, then install the libusb-win32 driver. To do this, the board must be connected and the CH55x must be in bootloader mode.

### Entering CH55x Bootloader Mode
A brand new chip starts automatically in bootloader mode as soon as it is connected to the PC via USB. Once firmware has been uploaded, the bootloader must be started manually for new uploads. To do this, the board must first be disconnected from the USB port and all voltage sources. Now press the BOOT button and keep it pressed while reconnecting the board to the USB port of your PC. The chip now starts again in bootloader mode, the BOOT button can be released and new firmware can be uploaded within the next couple of seconds.

## Compiling and Uploading using the makefile
### Installing SDCC Toolchain for CH55x
Install the [SDCC Compiler](https://sdcc.sourceforge.net/). In order for the programming tool to work, Python3 must be installed on your system. To do this, follow these [instructions](https://www.pythontutorial.net/getting-started/install-python/). In addition [pyusb](https://github.com/pyusb/pyusb) must be installed. On Linux (Debian-based), all of this can be done with the following commands:

```
sudo apt install build-essential sdcc python3 python3-pip
sudo pip install pyusb
```

### Compiling and Uploading Firmware
- Open a terminal.
- Navigate to the folder with the makefile. 
- Connect the board and make sure the CH55x ist in bootloader mode. 
- Run ```make flash``` to compile and upload the firmware. 
- If you don't want to compile the firmware yourself, you can also upload the precompiled binary. To do this, just run ```python3 ./tools/chprog.py macropad.bin```.

## Compiling and Uploading using the Arduino IDE
### Installing the Arduino IDE and CH55xduino
Install the [Arduino IDE](https://www.arduino.cc/en/software) if you haven't already. Install the [CH55xduino](https://github.com/DeqingSun/ch55xduino) package by following the instructions on the website.

### Compiling and Uploading Firmware
- Copy the .ino and .c files as well as the /src folder together into one folder and name it like the .ino file. 
- Open the .ino file in the Arduino IDE.
- Go to **Tools -> Board -> CH55x Boards** and select **CH552 Board**.
- Go to **Tools** and choose the following board options:
  - **Clock Source:**   16 MHz (internal)
  - **Upload Method:**  USB
  - **USB Settings:**   USER CODE /w 266B USB RAM
- Connect the board and make sure the CH55x ist in bootloader mode. 
- Click **Upload**.

# References, Links and Notes
1. [EasyEDA Design Files](https://oshwlab.com/wagiminator)
2. [CH551/552 Datasheet](http://www.wch-ic.com/downloads/CH552DS1_PDF.html)
3. [SDCC Compiler](https://sdcc.sourceforge.net/)

![Macropad_mini_pic4.jpg](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_pic4.jpg)
![Macropad_mini_pic5.jpg](https://raw.githubusercontent.com/wagiminator/CH552-Macropad-mini/main/documentation/Macropad_mini_pic5.jpg)

# License
![license.png](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

This work is licensed under Creative Commons Attribution-ShareAlike 3.0 Unported License. 
(http://creativecommons.org/licenses/by-sa/3.0/)
