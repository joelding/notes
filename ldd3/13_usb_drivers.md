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

- This chapter describes the interaction between a driver and the USB core.
- _USB core_: a subsystem provided by the Linux kernel

![gif](http://www.makelinux.net/ldd3/images/0596005903/figs/ldr3_1302.gif)

- A USB device consists of configurations, interfaces, and endpoints.
- _endpoint_: the most basic form of USB communication.
- A USB endpoint can carry data in only one direction (a unidirectional pipes), either from the host computer to the device (_an OUT endpoint_) or from the device to the host computer (an _IN endpoint_).
- A USB endpoint can be one of four different types that describe how the data is transmitted: control, interrupt, bulk, isochronous

- _Control endpoints_ are used 
 - to allow access to different parts of the USB device. 
 - for configuring the device, retrieving information about the device, sending commands to the device, or retrieving status reports about the device. 
 - usually small in size (they can hold lesss characters at once)
 - Every USB device has a control endpoint called "_endpoint 0_" that is used by the USB core to configure the device at insertion time. These transfers are guaranteed by the USB protocol to always have enough reserved bandwidth to make it through to the device.

- _Interrupt endpoints_ transfer small amounts of data at a fixed rate every time the USB host asks the device for data. 
 - the primary transport method for USB keyboards and mice. 
 - commonly used to send data to USB devices to control the device
 - not generally used to transfer large amounts of data
 - guaranteed by the USB protocol to always have enough reserved bandwidth

- _Bulk endpoints_ transfer large amounts of data. 
 - usually much larger (they can hold more characters at once) than interrupt endpoints.
 - for devices that need to transfer with no data loss. 
 - not guaranteed to always make it through in a specific amount of time
 - common on printers, storage, and network devices.

- _Isochronous endpoints_ also transfer large amounts of data
 - the data is not always guaranteed to make it through. 
 - These endpoints in devices can handle loss of data
 - Rely more on keeping a constant stream of data flowing. For example, real-time data collections, such as audio and video devices.

Control and buld endpoints used for asynchronous data transfers. Interrupt and isochronous endpoints are for periodic data transfers.

**struct usb\_host\_endpoint**: 
- USB endpoints are described in the kernel. 
-  contains the real endpoint information in another structure called **struct usb\_endpoint\_descriptor**


- An interface contains several USB endpoints
- An interface handles only one type of a USB logical connection.
- Some USB devices have multiple interfaces.

**struct usb\_interface**

A USB device can have and might switch among multiple configurations to change the state of the device. For example, some devices that allow firmware to be downloaded to them contain multiple configurations to accomplish this. A single configuration can be enabled only at one point in time.

**struct usb\_host\_config**
**struct usb\_device**

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
1. Jonathan Corbet, Alessandro Rubini, and Greg Kroah-Hartman, Linux Device Drivers, 3/e, O'reilly 2005

2. Linux Kernel Module Programming - USB Device Driver 01 [link](http://youtu.be/NYRhkGrt4Q4?list=PLM8zRjaI08aQKKdUIqObqLTp4o5A67pOy)

3. Linux Kernel Module Programming - USB Device Driver 02 [link](http://youtu.be/5IDL070RtoQ?list=PLM8zRjaI08aQKKdUIqObqLTp4o5A67pOy)

4. 任桥伟、肖季东、肖林甫，Linux那些事儿之我是USB（第2版），电子工业出版社 2012。_本书基于2.6.22内核，对USB子系统的大部分源代码逐行进行分析，系统地阐释了Linux内核中USB子系统是如何运转的，子系统内部的各个模块之间是如何互相协作、配合的。本次改版修改了第1版中出现的错误，增加了一个附录，主要内容是关于Linux内核的学习方法，是作者的经验总结，值得一读。 本书使用幽默诙谐的笔调对Linux内核中的USB子系统源代码进行了分析，形象且详尽地介绍了USB在Linux中的实现。本书从U盘、Hub、USB Core到主机控制器覆盖了USB实现的方方面面，被一些网友誉为USB开发的“圣经”。_

![img](http://218.249.32.138/web/9787121158179.jpg) 

5. 刘荣，圈圈教你玩USB（第2版），北京航空航天大学出版社 2013。_通过U盘、USB鼠标、USB键盘、USB MIDI键盘、USB转串口、自定义的USB HID设备和自定义的USB设备等几个具体的USB例子，一步步讲解USB设备及驱动程序和应用程序开发的详细过程和步骤。第9和10章介绍USB WDM驱动开发，并给出一个简单的USB驱动和USB上层过滤驱动的实例。第2版中新增4章内容，包括USB触摸屏设备、移植到AVR单片机和ARM微控制器上以及更多的USB设备的实现。本书附带的光盘中有USB学习板的电路图以及所有实验的完整源代码包（C/C++语言）。本书的读者对象主要是USB设备与驱动设计的初学者和提高者，以及所有对圈圈的支持者。_

![img](http://www.buaapress.com.cn/upload/book/9787512410923.jpg)

6. Jan Axelson, USB Complete - The Developer's Guide, Lakeview Research 2009. Jan Axelson's Lakeview Research [link](http://janaxelson.com/) 

![img](http://i4.ebkimg.com/previews/000/000434/000434434/000434434-hq-168-80.jpg)
