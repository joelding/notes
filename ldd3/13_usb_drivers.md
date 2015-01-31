#Chapter 13. USB Drivers

- _USB_: universal serial bus
- not laid out as a bus; rather a tree built out of several point-to-point links
- 4-wire cables: ground (black), power (red, +5V), and 2 signal wires (green Data+, white Data-)
- a USB device can never start sending data without first being asked to by the host controller.
- plug-and-play: devices can be automatically configured by the host computer.
- a single-master implementation: the host computer polls the various peripheral devices.
- a USB device can request a fixed bandwidth for its data transfers in order to reliably support video and audio I/O.
- USB acts as a communication channel between the device and the host without requiring specific meaning or structure to the data it delivers.
- types of devices: 
 - _classes_, a set of standards that any device of a specific type can follow. For these devices, a special driver is not necessary. For example: storage devices, keyboards, mice, joysticks, network devices, and modems.
 - Others: require a special vendor-specific driver. For example: video devices and USB-to-serial device.
- The Linux kernel supports two main types of USB drivers: drivers on a host system and drivers on a device (USB gadget drivers).
- This chapter details how the USB system that runs on a desktop computer works. USB gadget drivers are outside the realm of this book.

![gif](http://www.makelinux.net/ldd3/images/0596005903/figs/ldr3_1301.gif)

##13.1. USB Device Basics

_USB core_
- a subsystem provided by the Linux kernel

![gif](http://www.makelinux.net/ldd3/images/0596005903/figs/ldr3_1302.gif)

- USB devices consist of configurations, interfaces, and endpoints.
- USB drivers bind to USB interfaces, not the entire USB device.

##13.2. USB and Sysfs
##13.3. USB Urbs

urb
- USB request block
- The USB code in the Linux kernel use urbs to communicate with all USB devices. A urb is used to send or receive data to or from a specific USB endpoint on a specific USB device in an asynchronous manner. A USB device driver may allocate many urbs for a single endpoint or may reuse a single urb for many different endpoints. Every endpoint in a device can handle a queue of urbs.
- include/linux/usb.h
- struct urb
- The typical lifecycle:
 1. a USB device driver create a urb.
 2. a urb is assigned to a specific endpoint of a specific USB device.
 3. the USB device driver submits a urb to the USB core.
 4. the USB core submits to the specific USB host controller driver for the specified device.
 5. the USB host controller driver makes a USB transfer to the device.
 6. When the urb is completed, the USB host controller driver notifies the USB device driver.
- The driver that submitted the urb can cancel urbs any time; if the device is removed, the USB core can cancel urbs.






##13.4. Writing a USB Driver
##13.5. USB Transfers Without Urbs
##13.6. Quick Reference 

#REFERENCES
1. Linux Kernel Module Programming - USB Device Driver 01 [link](http://youtu.be/NYRhkGrt4Q4?list=PLM8zRjaI08aQKKdUIqObqLTp4o5A67pOy)
