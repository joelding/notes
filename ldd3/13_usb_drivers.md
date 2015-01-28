#Chapter 13. USB Drivers
##13.1. USB Device Basics
##13.2. USB and Sysfs
##13.3. USB Urbs

urb
- USB request block
- The USB code in the Linux kernel use urbs to communicate with all USB devices. A urb is used to send or receive data to or from a specific USB endpoint on a specific USB device in an asynchronous manner. A USB device driver may allocate many urbs for a single endpoint or may reuse a single urb for many different endpoints. Every endpoint in a device can handle a queue of urbs.
- include/linux/usb.h
- struct urb
- The typical lifecycle:
 - a USB device driver create a urb.
 - a urb is assigned to a specific endpoint of a specific USB device.
 - the USB device driver submits a urb to the USB core.
 - the USB core submits to the specific USB host controller driver for the specified device.
 - the USB host controller driver makes a USB transfer to the device.
 - When the urb is completed, the USB host controller driver notifies the USB device driver.


##13.4. Writing a USB Driver
##13.5. USB Transfers Without Urbs
##13.6. Quick Reference 
