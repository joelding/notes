http://goods.ruten.com.tw/item/show?21405112751885
=======
MIPS Creator CI20开发平台是采用君正JZ4780芯片，由Imagination公司负责设计的软硬件开源平台。
Ingenic Semiconductor
http://www.ingenic.cn

#RS232

canonical(正規模式)和non-canonical(非正規模式)。
正規模式又稱為cooked模式。終端設備會處理特殊字元，且會以一次一列的方式將輸入傳給應用程式。例如Linux的shell指令。
非正規模式又稱為raw模式。終端設備不會處理特殊字元，且會以一次一個字元的方式將輸入傳給應用程式。例如在Linux使用vim編輯程式。

[link](http://blog.xuite.net/uwlib_mud/twblog/108242774-Linux+RS-232+%E7%A8%8B%E5%BC%8F%E8%A8%AD%E8%A8%88)


#Writing Windows Programs with GTK+ and Qt
1. Install MinGW: go to MinGW website; find download; get "mingw-get-setup.exe" and execute.
2. Select "Basic Setup" package. Select mingw32-base and mingw32-gcc-g++ from the pacages.
3. Add "install_path\MinGW\bin" to PATH.
4. In Windows cmd, type "gcc -v" to test.
5. 


#wk10

耶穌呼召的門徒當中，唯獨雅各與約翰被提到時，有十一次被強調是「西庇太的兒子」。可見在早期教會中，西庇太這一家是信徒周知的家庭。西庇太這一家住在加利利海沿岸的漁村伯賽大，意思是指「捕魚之家」（約翰福音一章14節）。聖經記錄他們全家除父親西庇太之外，還有母親撒羅米以及兩個兒子雅各和約翰（馬可福音一章19-20節，十五章40節，馬太福音廿七章56節）。根據馬可福音一章20節記載，西庇太擁有自己的漁船，可見他的經濟條件還不錯；他還僱用了雇工幫忙捕魚，因此西庇太的捕魚事業應該具備一定的規模。
 
西庇太這一家是一個有影響力的家庭，以致當耶穌受審時，約翰還可以獲得大祭司的允准，進到公會當中一探究竟，因為社會地位崇高的大祭司竟然認識他！（參約翰福音十八章15-16節）。
 
雅各與約翰稱得上是當地加利利漁業界的小開，生活條件算是不錯。或許是良好的經濟條件養成他們驕妄的個性，所以他們兩個人共同擁有一個不太體面的渾名—半尼其，意思是「雷子」（馬可福音三章17節）。由此可知他們兩人暴躁衝動的性格。路加福音九章54節描述兩兄弟因為不滿撒瑪利亞人不接待耶穌，憤而要求耶穌讓他們吩咐火從天降，燒死撒瑪利亞人。我們從這些話可看到，他們張狂類比自己是以利亞先知，吹擂自己可以讓火從天降、烤焦撒瑪利亞人，還耶穌一個公道！

當耶穌呼召雅各與約翰時，他們的父親西庇太正在他們身邊。對一個傳統猶太人家庭而言，接續父業是一件重要的事情。西庇太這個家庭奉公守法，世世代代捕魚維生，兩個兒子將順理成章的繼承頗具規模的近海漁業，繼續在加利利海（又稱革尼撒勒湖）這片看似明鏡的湖面上過著平靜的捕魚生活。西庇太似乎沒有任何猶豫的選擇放手，讓兒子們離開他的事業，開始跟隨耶穌。

劉幸枝（衛理神學院教師）《從新約看家庭》全家事奉主─西庇太這一家 [link](http://www.ct.org.tw/news/detail/2015-00611) 基督教論壇報 2015-03-01

Linux From Scratch Version 7.0 [link](http://www.linuxfromscratch.org/lfs/view/7.0/index.html)

#wk09

「每一位基督徒的脖子上，都會掛一個『施工中』字樣的牌子，目的是提醒自己：要不斷成長、學習。我們人都不夠成熟，免不了會跌倒。」王純瑞，上帝給王雪紅的十堂課，大立文創 2014.10

USB B Connector: symbol and footprint [line](http://openhardware.ro/geda-library/)



生產測試的考量

板子預留治具可用的接點、測試點：可以擺單面、絕不擺雙面；可省則省，越少越好。

燒錄時間太長，則可能請廠商燒好再打到板子上，避免佔用產線燒錄。

RJ11和RJ45水晶头对应的4P2C, 4P4C, 6P2C, 6P4C, 6P6C, P和C是什么意思? P，是Position的简称，即位置，水晶头前端的凹槽个数；C，是Contact的简称，即触点，也就是我们看到的黄亮亮的金属触点。[link](http://www.pinzhi.org/thread-9318-1-1.html)

#wk07 08 ~ 14 February

Schematic Capture with gSchem [link](http://youtu.be/s5OPmICyGug)
gschem basics: add symbols and nets part 0 (Auyeung) [link](http://youtu.be/uan1Cdl0kA0)

int sqlite3_threadsafe(void);
returns zero if and only if SQLite was compiled 



#wk06

EDA Software for Linux

gEDA

select time, level, desc from log where (level > 5) AND (time > 16340);

Dear Steve,

"Log to SQLite database" is done. I will review myself next week and then commit.

Features:
1. Use avtlog interface. Users have options to log or not to log into the database.
2. The size of the log database (MAX_DBASE_SIZE) can be determined before compilation. If the size of the database file is over the pre-determined size, the oldest records will be deleted. The number of oldest records (DROP_ROWS) can also be set before compilation.
3. Add avt_getlog() to query the database with a partial SQL-compatible string. For example, "(time > 200) AND (level > 5)"

測試數據如下：
without database:
Time spent for 1000 time of log: 3026.578598026 to 3060.832590138 [~34 sec]

with 64kbytes database, 2000 log lines, 16 times oversized, 
Time spent for 1000 time of log: 3394.648303711 to 3573.654192364 [~179 sec]

with 4Mbytes database, no oversized.

Linux Kernel Cross Reference at lxr.oss.org.cn [link](http://lxr.oss.org.cn) for versions: 2.6.8, 2.6.16, 2.6.25, 2.6.30, 2.6.34, 2.6.35, 2.6.39, 3.0.26, 3.2.20, 3.4.9, 3.10, 3.12, 3.13, 3.17.
Linux Kernel Cross Reference at Free Electrons [link](http://lxr.free-electrons.com) for version:  2.0.40, 2.2.26, 2.4.37, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7 3.8 3.9 3.10 3.11 3.12 3.13 3.14 3.15 3.16 3.17 3.18



#2015/01/29 THU
Gary Frerking, [Serial Programming HOWTO](http://www.faqs.org/docs/Linux-HOWTO/Serial-Programming-HOWTO.html)
 
David S.Lawyer, original by Greg Hankins, [Serial HOWTO](http://www.tldp.org/HOWTO/Serial-HOWTO.html)


 The newer cp2104 devices require the baud rate to be initialised after power on. Make sure it is set when port is opened.

Author: Johan Hovold <jhovold@gmail.com>
Date:   Mon Jan 16 00:36:52 2012 +0100
[link](http://ftp.kernel.org/pub/linux/kernel/v3.x/ChangeLog-3.2.3)

Bus 001 Device 022: ID 10c4:ea60 Cygnal Integrated Products, Inc. CP210x UART Bridge / myAVR mySmartUSB light


ftdi_sio               48930  0 
usbserial              45014  2 cp210x,ftdi_sio

2.6.21
usb-serial.c
struct usb\_serial\_driver
user\_serial\_register
user\_serial\_deregister
user\_serial\_probe
user\_serial\_disconnect
user\_serial\_port_softint

[USBView](http://www.kroah.com/linux-usb/) is a GTK program that displays the topography of the devices that are plugged into the USB bus on a Linux machine. It also displays information on each of the devices. This can be useful to determine if a device is working properly or not.

Dear Steve,

如您所知， Silicon Labs CP210x USB 至 UART 橋 VCP 驅動，是給核心2.6.38用的。.21和.38，不論是資料結構、函數參數都不盡相同。
http://www.silabs.com/Support%20Documents/Software/Linux_2.6.x_VCP_Driver_Source.zip

難怪，從2.6.21核心編譯，馬上出現警告
  CC [M]  drivers/usb/serial/cp210x.o
drivers/usb/serial/cp210x.c:179: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:180: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:181: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:182: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:183: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:184: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:185: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:987: warning: 'cp210x_release' defined but not used
drivers/usb/serial/cp210x.c:999: warning: 'cp210x_disconnect' defined but not used
drivers/usb/serial/cp210x.c:913: warning: 'cp210x_dtr_rts' defined but not used

我想，是不是應該從2.6.21的驅動cp2101.c改起：使用cp2101.c的函數的形狀，把原廠210x.c對CP2104的控制搬過來。










sudo mount -t cifs "//10.1.9.195/SCM/GIT/" /mnt/SCM/GIT/ -o soft,username=a003257
[sudo] password for a003257: 
Password for a003257@//10.1.9.195/SCM/GIT/: 

git clone /mnt/SCM/GIT/Embedded/RT3662/F239/AVerCasterHDDuet


Bus 001 Device 009: ID 10c4:ea60 Cygnal Integrated Products, Inc. CP210x UART Bridge / myAVR mySmartUSB light
Bus 001 Device 008: ID 1a40:0101 Terminus Technology Inc. 4-Port HUB

In December, 2003, Silicon Labs acquired Cygnal Integrated Products, an Austin-based innovator of analog-intensive, highly integrated 8-bit microcontrollers (MCUs). [link](http://en.wikipedia.org/wiki/Silicon_Labs)


Jan 27 13:31:39 A003257 kernel: [17003.024044] usb 1-1: new high-speed USB device number 16 using ehci-pci
Jan 27 13:31:39 A003257 kernel: [17003.156609] usb 1-1: New USB device found, idVendor=1a40, idProduct=0101
Jan 27 13:31:39 A003257 kernel: [17003.156617] usb 1-1: New USB device strings: Mfr=0, Product=1, SerialNumber=0
Jan 27 13:31:39 A003257 kernel: [17003.156622] usb 1-1: Product: USB 2.0 Hub
Jan 27 13:31:39 A003257 kernel: [17003.156922] hub 1-1:1.0: USB hub found
Jan 27 13:31:39 A003257 kernel: [17003.156978] hub 1-1:1.0: 4 ports detected
Jan 27 13:31:39 A003257 kernel: [17003.444116] usb 1-1.1: new full-speed USB device number 17 using ehci-pci
Jan 27 13:31:40 A003257 kernel: [17003.554613] usb 1-1.1: New USB device found, idVendor=10c4, idProduct=ea60
Jan 27 13:31:40 A003257 kernel: [17003.554621] usb 1-1.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:40 A003257 kernel: [17003.554627] usb 1-1.1: Product: CP2104 USB to UART Bridge Controller
Jan 27 13:31:40 A003257 kernel: [17003.554631] usb 1-1.1: Manufacturer: Silicon Labs
Jan 27 13:31:40 A003257 kernel: [17003.554636] usb 1-1.1: SerialNumber: 00807154
Jan 27 13:31:40 A003257 kernel: [17003.555412] cp210x 1-1.1:1.0: cp210x converter detected
Jan 27 13:31:40 A003257 kernel: [17003.644119] usb 1-1.1: reset full-speed USB device number 17 using ehci-pci
Jan 27 13:31:40 A003257 kernel: [17003.752927] usb 1-1.1: cp210x converter now attached to ttyUSB0
Jan 27 13:31:40 A003257 mtp-probe: checking bus 1, device 17: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.1"
Jan 27 13:31:40 A003257 mtp-probe: bus: 1, device: 17 was not an MTP device
Jan 27 13:31:42 A003257 kernel: [17005.535349] usb 1-1: USB disconnect, device number 16
Jan 27 13:31:42 A003257 kernel: [17005.535357] usb 1-1.1: USB disconnect, device number 17
Jan 27 13:31:42 A003257 kernel: [17005.535633] cp210x ttyUSB0: cp210x converter now disconnected from ttyUSB0
Jan 27 13:31:42 A003257 kernel: [17005.535660] cp210x 1-1.1:1.0: device disconnected
Jan 27 13:31:44 A003257 kernel: [17007.780079] usb 1-1: new high-speed USB device number 18 using ehci-pci
Jan 27 13:31:44 A003257 kernel: [17007.912641] usb 1-1: New USB device found, idVendor=1a40, idProduct=0101
Jan 27 13:31:44 A003257 kernel: [17007.912650] usb 1-1: New USB device strings: Mfr=0, Product=1, SerialNumber=0
Jan 27 13:31:44 A003257 kernel: [17007.912655] usb 1-1: Product: USB 2.0 Hub
Jan 27 13:31:44 A003257 kernel: [17007.913224] hub 1-1:1.0: USB hub found
Jan 27 13:31:44 A003257 kernel: [17007.913391] hub 1-1:1.0: 4 ports detected
Jan 27 13:31:44 A003257 kernel: [17008.200150] usb 1-1.1: new full-speed USB device number 19 using ehci-pci
Jan 27 13:31:44 A003257 kernel: [17008.310647] usb 1-1.1: New USB device found, idVendor=10c4, idProduct=ea60
Jan 27 13:31:44 A003257 kernel: [17008.310656] usb 1-1.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:44 A003257 kernel: [17008.310661] usb 1-1.1: Product: CP2104 USB to UART Bridge Controller
Jan 27 13:31:44 A003257 kernel: [17008.310666] usb 1-1.1: Manufacturer: Silicon Labs
Jan 27 13:31:44 A003257 kernel: [17008.310670] usb 1-1.1: SerialNumber: 00807154
Jan 27 13:31:44 A003257 kernel: [17008.311446] cp210x 1-1.1:1.0: cp210x converter detected
Jan 27 13:31:44 A003257 kernel: [17008.400161] usb 1-1.1: reset full-speed USB device number 19 using ehci-pci
Jan 27 13:31:45 A003257 kernel: [17008.508995] usb 1-1.1: cp210x converter now attached to ttyUSB0
Jan 27 13:31:45 A003257 mtp-probe: checking bus 1, device 19: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.1"
Jan 27 13:31:45 A003257 mtp-probe: bus: 1, device: 19 was not an MTP device
Jan 27 13:31:47 A003257 kernel: [17011.340191] usb 1-1.3: new high-speed USB device number 20 using ehci-pci
Jan 27 13:31:48 A003257 kernel: [17012.108083] usb 1-1.3: new high-speed USB device number 21 using ehci-pci
Jan 27 13:31:48 A003257 kernel: [17012.344706] usb 1-1.3: New USB device found, idVendor=07ca, idProduct=0910
Jan 27 13:31:48 A003257 kernel: [17012.344714] usb 1-1.3: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:48 A003257 kernel: [17012.344719] usb 1-1.3: Product: AVer_CV910_USB
Jan 27 13:31:48 A003257 kernel: [17012.344724] usb 1-1.3: Manufacturer: AVerMedia Tech. Inc.
Jan 27 13:31:48 A003257 kernel: [17012.344728] usb 1-1.3: SerialNumber: FFFFFFFFFF
Jan 27 13:31:48 A003257 mtp-probe: checking bus 1, device 21: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.3"
Jan 27 13:31:48 A003257 mtp-probe: bus: 1, device: 21 was not an MTP device



# busybox
BusyBox v1.12.1 (2014-12-05 20:44:15 CST) multi-call binary
Copyright (C) 1998-2008 Erik Andersen, Rob Landley, Denys Vlasenko
and others. Licensed under GPLv2.
See source distribution for full notice.

Usage: busybox [function] [arguments]...
   or: function [arguments]...

        BusyBox is a multi-call binary that combines many common Unix
        utilities into a single executable.  Most people will create a
        link to busybox for each function they wish to use and BusyBox
        will act like whatever it was invoked as!

Currently defined functions:
        [, [[, ash, awk, basename, brctl, cat, chmod, chpasswd, cksum,
        cp, cut, date, df, du, echo, expr, fdisk, free, grep, halt, hostname,
        hwclock, ifconfig, init, init, insmod, kill, killall, klogd, ln,
        logger, login, logread, ls, lsmod, md5sum, mdev, mkdir, mkfs.minix,
        mknod, mount, mv, ping, poweroff, printenv, printf, ps, pwd, reboot,
        rm, rmmod, route, sed, sh, sleep, sync, syslogd, tail, tar, tee,
        telnetd, test, tftp, top, touch, udhcpc, udhcpd, umount, uncompress,
        uptime, usleep, vconfig, vi, wc



 git checkout JADE_20140901

~$ sudo apt-get install tftp-hpa


# 
usb 1-2.3: new high speed USB device using rt3xxx-ehci and address 3
usb 1-2.3: Product: USB 2.0 Hub
usb 1-2.3: configuration #1 chosen from 1 choice
hub 1-2.3:1.0: USB hub found
hub 1-2.3:1.0: 4 ports detected
usb 1-2.3: USB disconnect, address 3
usb 1-2.3: new high speed USB device using rt3xxx-ehci and address 4
usb 1-2.3: Product: USB 2.0 Hub
usb 1-2.3: configuration #1 chosen from 1 choice
hub 1-2.3:1.0: USB hub found
hub 1-2.3:1.0: 4 ports detected
usb 1-2.3.1: new full speed USB device using rt3xxx-ehci and address 5
usb 1-2.3.1: Product: CP2104 USB to UART Bridge Controller
usb 1-2.3.1: Manufacturer: Silicon Labs
usb 1-2.3.1: SerialNumber: 00807154
usb 1-2.3.1: configuration #1 chosen from 1 choice
cp210x 1-2.3.1:1.0: cp210x converter detected
usb 1-2.3.1: cp210x converter now attached to ttyUSB0
usb 1-2.3.3: new high speed USB device using rt3xxx-ehci and address 6
usb 1-2.3.3: Product: AVer_CV910_USB
usb 1-2.3.3: Manufacturer: AVerMedia Tech. Inc.
usb 1-2.3.3: SerialNumber: FFFFFFFFFF
usb 1-2.3.3: configuration #1 chosen from 1 choice

#Virtual COM Port
The CP210x USB to UART Bridge Virtual COM Port (VCP) drivers are required for device operation as a Virtual COM Port to facilitate host communication with CP210x products. These devices can also interface to a host using the USBXpress direct access driver. These drivers are static examples detailed in application note 197: The Serial Communications Guide for the CP210x, download an example below: 


Virtual COM port (VCP) drivers cause the USB device to appear as an additional COM port available to the PC.  Application software can access the USB device in the same way as it would access a standard COM port. [link](http://www.ftdichip.com/Drivers/VCP.htm)

kernel Documentation/usb/usb-serial.txt
- the major number: 188
- up to 256 different serial interfaces

\# ls /dev/ttyUS* -l
crw-rw----    1 0        0        188,   0 /dev/ttyUSB0

generic serial driver
- drivers/usb/serial/generic.c
- no any type of control messages sent to the device
- no support any kind of device flow control
- at least one bulk in endpoint, or one buld out endpoint


the home of the Linux USB Project [link](http://www.linux-usb.org/)



















http://www.mcc-us.com/usinglinuxvcp.htm


**彼得前書 2:18~25**
**你們作僕人的，凡事要存敬畏的心順服主人；不但順服那善良溫和的，就是那乖僻的也要順服。**
**倘若人為叫良心對得住神，就忍受冤屈的苦楚，這是可喜愛的。**
**你們若因犯罪受責打，能忍耐，有什麼可誇的呢？但你們若因行善受苦，能忍耐，這在神看是可喜愛的。**
**你們蒙召原是為此；因基督也為你們受過苦，給你們留下榜樣，叫你們跟隨他的腳蹤行。**
**他並沒有犯罪，口裡也沒有詭詐。**
**他被罵不還口；受害不說威嚇的話，只將自己交託那按公義審判人的主。**
**他被掛在木頭上，親身擔當了我們的罪，使我們既然在罪上死，就得以在義上活。因他受的鞭傷，你們便得了醫治。**
**你們從前好像迷路的羊，如今卻歸到你們靈魂的牧人監督了。**

# echo "Test" > /dev/ttyUSB0
CPU 0 Unable to handle kernel paging request at virtual address 00000000, epc == 802b3220, ra == 802b3c20
Oops[#1]:
Cpu 0
$ 0   : 00000000 7ff605e0 87da0140 00000001
$ 4   : 807c7720 80000000 00000000 00000041
$ 8   : 00000020 801d6c90 00000044 ffffffff
$12   : 8111b108 ffffffff 00200200 00100100
$16   : 87da0140 00000000 807c7720 807c7798
$20   : 00000000 87da0140 00000000 00000041
$24   : 00000002 80350000                  
$28   : 81160000 81161d20 00000000 802b3c20
Hi    : 0000005e
Lo    : 5e5e5ebc
epc   : 802b3220 cp210x_set_config+0xf8/0x1a8     Not tainted
ra    : 802b3c20 cp210x_open+0x68/0x168
Status: 1100fc03    KERNEL EXL IE 
Cause : 00800008
BadVA : 00000000
PrId  : 0001974c
Modules linked in:
Process sh (pid: 774, threadinfo=81160000, task=8116f000)
Stack : 000200d0 ffffffff 87da0068 00000044 00000001 00000000 87da0000 87da0000
        00000000 0bc00000 87da0140 807c7720 87d5ac00 87d5ac08 87da0000 00000001
        807c7720 ffffffff 004b2788 802b3c20 801e83cc 801e83bc 0000540d 00000001
        00000000 00000000 87d62500 802af08c ffffff9c 00000310 87d5ac00 87d62500
        fffffe00 802af270 804f9580 00000000 81277804 807c7720 ffffffed 807c7720
        ...
Call Trace:
[<802b3220>] cp210x_set_config+0xf8/0x1a8
[<802b3c20>] cp210x_open+0x68/0x168
[<802af270>] serial_open+0x198/0x204
[<801e5488>] tty_open+0x1c8/0x318
[<80086618>] chrdev_open+0x250/0x28c
[<80081740>] __dentry_open+0x194/0x2ec
[<800818c8>] nameidata_to_filp+0x30/0x54
[<80081930>] do_filp_open+0x44/0x60
[<80081df4>] do_sys_open+0x6c/0xd0
[<80013f64>] stack_done+0x20/0x3c


Code: 3043ffff  8c820000  afa30010 <92c30000> 00021200  00452825  3282ffff  afa2001c  03c03021 
process '/bin/sh' (pid 774) exited. Scheduling for restart.




usb 1-2.3: new full speed USB device using rt3xxx-ehci and address 3
usb 1-2.3: Product: FT232R USB UART
usb 1-2.3: Manufacturer: FTDI
usb 1-2.3: SerialNumber: A600IM9L
usb 1-2.3: configuration #1 chosen from 1 choice
ftdi_sio 1-2.3:1.0: FTDI USB Serial Device converter detected
drivers/usb/serial/ftdi_sio.c: Detected FT232RL
usb 1-2.3: FTDI USB Serial Device converter now attached to ttyUSB0



[Understanding a Kernel Oops!](http://www.opensourceforu.com/2011/01/understanding-a-kernel-oops/)
- panics in the Linux kernel are classified as 
 1. hard panics (Aiee!)
 2. soft panics (Oops!). 
Call Trace: the list of functions being called just before the Oops occurred.

CP210x USB 至 UART 橋 VCP 驅動器[下載](http://www.silabs.com/Support%20Documents/Software/Linux_3.x.x_VCP_Driver_Source.zip)
http://www.silabs.com/Support%20Documents/Software/Linux_2.6.x_VCP_Driver_Source.zip


usb\_control\_msg - Builds a control urb, sends it off and waits for completion


  CC [M]  drivers/usb/serial/cp210x.o
drivers/usb/serial/cp210x.c:179: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:180: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:181: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:182: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:183: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:184: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:185: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:987: warning: 'cp210x_release' defined but not used
drivers/usb/serial/cp210x.c:999: warning: 'cp210x_disconnect' defined but not used
drivers/usb/serial/cp210x.c:913: warning: 'cp210x_dtr_rts' defined but not used

_baud rate_ the unit for symbol rate or modulation rate in symbols per second, pulses per second, or bits per second (bit/s, 每秒鐘多少位元). Unit symbol **Bd**.

![duration time Ts](http://upload.wikimedia.org/math/f/9/9/f99b8d28f1062d8307f750dd083d9a67.png)


data byte 是 8-bit
傳輸的時候，一般用 n, 8, 1, 即 n parity bit, 8 data bits, 1 stop bit
所以一個 byte 傳輸時，實際是 1 start bit + 8 data bits + 1 stop bit = 10 bits

9600 / 10 = 960 bytes

計算傳輸的速度 9600 bps，一秒鐘可以傳 960 bytes

















#2015/01/28 WED
Dear Steve,

如您所知， Silicon Labs CP210x USB 至 UART 橋 VCP 驅動，是給核心2.6.38用的。.21和.38，不論是資料結構、函數參數都不盡相同。
http://www.silabs.com/Support%20Documents/Software/Linux_2.6.x_VCP_Driver_Source.zip

難怪，從2.6.21核心編譯，馬上出現警告
  CC [M]  drivers/usb/serial/cp210x.o
drivers/usb/serial/cp210x.c:179: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:180: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:181: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:182: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:183: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:184: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:185: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:987: warning: 'cp210x_release' defined but not used
drivers/usb/serial/cp210x.c:999: warning: 'cp210x_disconnect' defined but not used
drivers/usb/serial/cp210x.c:913: warning: 'cp210x_dtr_rts' defined but not used

我想，是不是應該從2.6.21的驅動cp2101.c改起：使用cp2101.c的函數的形狀，把原廠210x.c對CP2104的控制搬過來。










sudo mount -t cifs "//10.1.9.195/SCM/GIT/" /mnt/SCM/GIT/ -o soft,username=a003257
[sudo] password for a003257: 
Password for a003257@//10.1.9.195/SCM/GIT/: 

git clone /mnt/SCM/GIT/Embedded/RT3662/F239/AVerCasterHDDuet


Bus 001 Device 009: ID 10c4:ea60 Cygnal Integrated Products, Inc. CP210x UART Bridge / myAVR mySmartUSB light
Bus 001 Device 008: ID 1a40:0101 Terminus Technology Inc. 4-Port HUB

In December, 2003, Silicon Labs acquired Cygnal Integrated Products, an Austin-based innovator of analog-intensive, highly integrated 8-bit microcontrollers (MCUs). [link](http://en.wikipedia.org/wiki/Silicon_Labs)


Jan 27 13:31:39 A003257 kernel: [17003.024044] usb 1-1: new high-speed USB device number 16 using ehci-pci
Jan 27 13:31:39 A003257 kernel: [17003.156609] usb 1-1: New USB device found, idVendor=1a40, idProduct=0101
Jan 27 13:31:39 A003257 kernel: [17003.156617] usb 1-1: New USB device strings: Mfr=0, Product=1, SerialNumber=0
Jan 27 13:31:39 A003257 kernel: [17003.156622] usb 1-1: Product: USB 2.0 Hub
Jan 27 13:31:39 A003257 kernel: [17003.156922] hub 1-1:1.0: USB hub found
Jan 27 13:31:39 A003257 kernel: [17003.156978] hub 1-1:1.0: 4 ports detected
Jan 27 13:31:39 A003257 kernel: [17003.444116] usb 1-1.1: new full-speed USB device number 17 using ehci-pci
Jan 27 13:31:40 A003257 kernel: [17003.554613] usb 1-1.1: New USB device found, idVendor=10c4, idProduct=ea60
Jan 27 13:31:40 A003257 kernel: [17003.554621] usb 1-1.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:40 A003257 kernel: [17003.554627] usb 1-1.1: Product: CP2104 USB to UART Bridge Controller
Jan 27 13:31:40 A003257 kernel: [17003.554631] usb 1-1.1: Manufacturer: Silicon Labs
Jan 27 13:31:40 A003257 kernel: [17003.554636] usb 1-1.1: SerialNumber: 00807154
Jan 27 13:31:40 A003257 kernel: [17003.555412] cp210x 1-1.1:1.0: cp210x converter detected
Jan 27 13:31:40 A003257 kernel: [17003.644119] usb 1-1.1: reset full-speed USB device number 17 using ehci-pci
Jan 27 13:31:40 A003257 kernel: [17003.752927] usb 1-1.1: cp210x converter now attached to ttyUSB0
Jan 27 13:31:40 A003257 mtp-probe: checking bus 1, device 17: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.1"
Jan 27 13:31:40 A003257 mtp-probe: bus: 1, device: 17 was not an MTP device
Jan 27 13:31:42 A003257 kernel: [17005.535349] usb 1-1: USB disconnect, device number 16
Jan 27 13:31:42 A003257 kernel: [17005.535357] usb 1-1.1: USB disconnect, device number 17
Jan 27 13:31:42 A003257 kernel: [17005.535633] cp210x ttyUSB0: cp210x converter now disconnected from ttyUSB0
Jan 27 13:31:42 A003257 kernel: [17005.535660] cp210x 1-1.1:1.0: device disconnected
Jan 27 13:31:44 A003257 kernel: [17007.780079] usb 1-1: new high-speed USB device number 18 using ehci-pci
Jan 27 13:31:44 A003257 kernel: [17007.912641] usb 1-1: New USB device found, idVendor=1a40, idProduct=0101
Jan 27 13:31:44 A003257 kernel: [17007.912650] usb 1-1: New USB device strings: Mfr=0, Product=1, SerialNumber=0
Jan 27 13:31:44 A003257 kernel: [17007.912655] usb 1-1: Product: USB 2.0 Hub
Jan 27 13:31:44 A003257 kernel: [17007.913224] hub 1-1:1.0: USB hub found
Jan 27 13:31:44 A003257 kernel: [17007.913391] hub 1-1:1.0: 4 ports detected
Jan 27 13:31:44 A003257 kernel: [17008.200150] usb 1-1.1: new full-speed USB device number 19 using ehci-pci
Jan 27 13:31:44 A003257 kernel: [17008.310647] usb 1-1.1: New USB device found, idVendor=10c4, idProduct=ea60
Jan 27 13:31:44 A003257 kernel: [17008.310656] usb 1-1.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:44 A003257 kernel: [17008.310661] usb 1-1.1: Product: CP2104 USB to UART Bridge Controller
Jan 27 13:31:44 A003257 kernel: [17008.310666] usb 1-1.1: Manufacturer: Silicon Labs
Jan 27 13:31:44 A003257 kernel: [17008.310670] usb 1-1.1: SerialNumber: 00807154
Jan 27 13:31:44 A003257 kernel: [17008.311446] cp210x 1-1.1:1.0: cp210x converter detected
Jan 27 13:31:44 A003257 kernel: [17008.400161] usb 1-1.1: reset full-speed USB device number 19 using ehci-pci
Jan 27 13:31:45 A003257 kernel: [17008.508995] usb 1-1.1: cp210x converter now attached to ttyUSB0
Jan 27 13:31:45 A003257 mtp-probe: checking bus 1, device 19: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.1"
Jan 27 13:31:45 A003257 mtp-probe: bus: 1, device: 19 was not an MTP device
Jan 27 13:31:47 A003257 kernel: [17011.340191] usb 1-1.3: new high-speed USB device number 20 using ehci-pci
Jan 27 13:31:48 A003257 kernel: [17012.108083] usb 1-1.3: new high-speed USB device number 21 using ehci-pci
Jan 27 13:31:48 A003257 kernel: [17012.344706] usb 1-1.3: New USB device found, idVendor=07ca, idProduct=0910
Jan 27 13:31:48 A003257 kernel: [17012.344714] usb 1-1.3: New USB device strings: Mfr=1, Product=2, SerialNumber=3
Jan 27 13:31:48 A003257 kernel: [17012.344719] usb 1-1.3: Product: AVer_CV910_USB
Jan 27 13:31:48 A003257 kernel: [17012.344724] usb 1-1.3: Manufacturer: AVerMedia Tech. Inc.
Jan 27 13:31:48 A003257 kernel: [17012.344728] usb 1-1.3: SerialNumber: FFFFFFFFFF
Jan 27 13:31:48 A003257 mtp-probe: checking bus 1, device 21: "/sys/devices/pci0000:00/0000:00:1d.7/usb1/1-1/1-1.3"
Jan 27 13:31:48 A003257 mtp-probe: bus: 1, device: 21 was not an MTP device



# busybox
BusyBox v1.12.1 (2014-12-05 20:44:15 CST) multi-call binary
Copyright (C) 1998-2008 Erik Andersen, Rob Landley, Denys Vlasenko
and others. Licensed under GPLv2.
See source distribution for full notice.

Usage: busybox [function] [arguments]...
   or: function [arguments]...

        BusyBox is a multi-call binary that combines many common Unix
        utilities into a single executable.  Most people will create a
        link to busybox for each function they wish to use and BusyBox
        will act like whatever it was invoked as!

Currently defined functions:
        [, [[, ash, awk, basename, brctl, cat, chmod, chpasswd, cksum,
        cp, cut, date, df, du, echo, expr, fdisk, free, grep, halt, hostname,
        hwclock, ifconfig, init, init, insmod, kill, killall, klogd, ln,
        logger, login, logread, ls, lsmod, md5sum, mdev, mkdir, mkfs.minix,
        mknod, mount, mv, ping, poweroff, printenv, printf, ps, pwd, reboot,
        rm, rmmod, route, sed, sh, sleep, sync, syslogd, tail, tar, tee,
        telnetd, test, tftp, top, touch, udhcpc, udhcpd, umount, uncompress,
        uptime, usleep, vconfig, vi, wc



 git checkout JADE_20140901

~$ sudo apt-get install tftp-hpa


# 
usb 1-2.3: new high speed USB device using rt3xxx-ehci and address 3
usb 1-2.3: Product: USB 2.0 Hub
usb 1-2.3: configuration #1 chosen from 1 choice
hub 1-2.3:1.0: USB hub found
hub 1-2.3:1.0: 4 ports detected
usb 1-2.3: USB disconnect, address 3
usb 1-2.3: new high speed USB device using rt3xxx-ehci and address 4
usb 1-2.3: Product: USB 2.0 Hub
usb 1-2.3: configuration #1 chosen from 1 choice
hub 1-2.3:1.0: USB hub found
hub 1-2.3:1.0: 4 ports detected
usb 1-2.3.1: new full speed USB device using rt3xxx-ehci and address 5
usb 1-2.3.1: Product: CP2104 USB to UART Bridge Controller
usb 1-2.3.1: Manufacturer: Silicon Labs
usb 1-2.3.1: SerialNumber: 00807154
usb 1-2.3.1: configuration #1 chosen from 1 choice
cp210x 1-2.3.1:1.0: cp210x converter detected
usb 1-2.3.1: cp210x converter now attached to ttyUSB0
usb 1-2.3.3: new high speed USB device using rt3xxx-ehci and address 6
usb 1-2.3.3: Product: AVer_CV910_USB
usb 1-2.3.3: Manufacturer: AVerMedia Tech. Inc.
usb 1-2.3.3: SerialNumber: FFFFFFFFFF
usb 1-2.3.3: configuration #1 chosen from 1 choice

#Virtual COM Port
The CP210x USB to UART Bridge Virtual COM Port (VCP) drivers are required for device operation as a Virtual COM Port to facilitate host communication with CP210x products. These devices can also interface to a host using the USBXpress direct access driver. These drivers are static examples detailed in application note 197: The Serial Communications Guide for the CP210x, download an example below: 


Virtual COM port (VCP) drivers cause the USB device to appear as an additional COM port available to the PC.  Application software can access the USB device in the same way as it would access a standard COM port. [link](http://www.ftdichip.com/Drivers/VCP.htm)

kernel Documentation/usb/usb-serial.txt
- the major number: 188
- up to 256 different serial interfaces

\# ls /dev/ttyUS* -l
crw-rw----    1 0        0        188,   0 /dev/ttyUSB0

generic serial driver
- drivers/usb/serial/generic.c
- no any type of control messages sent to the device
- no support any kind of device flow control
- at least one bulk in endpoint, or one buld out endpoint


the home of the Linux USB Project [link](http://www.linux-usb.org/)



















http://www.mcc-us.com/usinglinuxvcp.htm


**彼得前書 2:18~25**
**你們作僕人的，凡事要存敬畏的心順服主人；不但順服那善良溫和的，就是那乖僻的也要順服。**
**倘若人為叫良心對得住神，就忍受冤屈的苦楚，這是可喜愛的。**
**你們若因犯罪受責打，能忍耐，有什麼可誇的呢？但你們若因行善受苦，能忍耐，這在神看是可喜愛的。**
**你們蒙召原是為此；因基督也為你們受過苦，給你們留下榜樣，叫你們跟隨他的腳蹤行。**
**他並沒有犯罪，口裡也沒有詭詐。**
**他被罵不還口；受害不說威嚇的話，只將自己交託那按公義審判人的主。**
**他被掛在木頭上，親身擔當了我們的罪，使我們既然在罪上死，就得以在義上活。因他受的鞭傷，你們便得了醫治。**
**你們從前好像迷路的羊，如今卻歸到你們靈魂的牧人監督了。**

# echo "Test" > /dev/ttyUSB0
CPU 0 Unable to handle kernel paging request at virtual address 00000000, epc == 802b3220, ra == 802b3c20
Oops[#1]:
Cpu 0
$ 0   : 00000000 7ff605e0 87da0140 00000001
$ 4   : 807c7720 80000000 00000000 00000041
$ 8   : 00000020 801d6c90 00000044 ffffffff
$12   : 8111b108 ffffffff 00200200 00100100
$16   : 87da0140 00000000 807c7720 807c7798
$20   : 00000000 87da0140 00000000 00000041
$24   : 00000002 80350000                  
$28   : 81160000 81161d20 00000000 802b3c20
Hi    : 0000005e
Lo    : 5e5e5ebc
epc   : 802b3220 cp210x_set_config+0xf8/0x1a8     Not tainted
ra    : 802b3c20 cp210x_open+0x68/0x168
Status: 1100fc03    KERNEL EXL IE 
Cause : 00800008
BadVA : 00000000
PrId  : 0001974c
Modules linked in:
Process sh (pid: 774, threadinfo=81160000, task=8116f000)
Stack : 000200d0 ffffffff 87da0068 00000044 00000001 00000000 87da0000 87da0000
        00000000 0bc00000 87da0140 807c7720 87d5ac00 87d5ac08 87da0000 00000001
        807c7720 ffffffff 004b2788 802b3c20 801e83cc 801e83bc 0000540d 00000001
        00000000 00000000 87d62500 802af08c ffffff9c 00000310 87d5ac00 87d62500
        fffffe00 802af270 804f9580 00000000 81277804 807c7720 ffffffed 807c7720
        ...
Call Trace:
[<802b3220>] cp210x_set_config+0xf8/0x1a8
[<802b3c20>] cp210x_open+0x68/0x168
[<802af270>] serial_open+0x198/0x204
[<801e5488>] tty_open+0x1c8/0x318
[<80086618>] chrdev_open+0x250/0x28c
[<80081740>] __dentry_open+0x194/0x2ec
[<800818c8>] nameidata_to_filp+0x30/0x54
[<80081930>] do_filp_open+0x44/0x60
[<80081df4>] do_sys_open+0x6c/0xd0
[<80013f64>] stack_done+0x20/0x3c


Code: 3043ffff  8c820000  afa30010 <92c30000> 00021200  00452825  3282ffff  afa2001c  03c03021 
process '/bin/sh' (pid 774) exited. Scheduling for restart.




usb 1-2.3: new full speed USB device using rt3xxx-ehci and address 3
usb 1-2.3: Product: FT232R USB UART
usb 1-2.3: Manufacturer: FTDI
usb 1-2.3: SerialNumber: A600IM9L
usb 1-2.3: configuration #1 chosen from 1 choice
ftdi_sio 1-2.3:1.0: FTDI USB Serial Device converter detected
drivers/usb/serial/ftdi_sio.c: Detected FT232RL
usb 1-2.3: FTDI USB Serial Device converter now attached to ttyUSB0



[Understanding a Kernel Oops!](http://www.opensourceforu.com/2011/01/understanding-a-kernel-oops/)
- panics in the Linux kernel are classified as 
 1. hard panics (Aiee!)
 2. soft panics (Oops!). 
Call Trace: the list of functions being called just before the Oops occurred.

CP210x USB 至 UART 橋 VCP 驅動器[下載](http://www.silabs.com/Support%20Documents/Software/Linux_3.x.x_VCP_Driver_Source.zip)
http://www.silabs.com/Support%20Documents/Software/Linux_2.6.x_VCP_Driver_Source.zip


usb\_control\_msg - Builds a control urb, sends it off and waits for completion


  CC [M]  drivers/usb/serial/cp210x.o
drivers/usb/serial/cp210x.c:179: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:180: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:181: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:182: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:183: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:184: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:185: warning: initialization from incompatible pointer type
drivers/usb/serial/cp210x.c:987: warning: 'cp210x_release' defined but not used
drivers/usb/serial/cp210x.c:999: warning: 'cp210x_disconnect' defined but not used
drivers/usb/serial/cp210x.c:913: warning: 'cp210x_dtr_rts' defined but not used


Jeremy Bentham, TCP/IP Lean: Web Servers for Embedded Systems, 2/E, CRC Press 2002

Jeremy Bentham comes from Cambridge, England. This book is a hands-on book about TCP/IP networking.

An engineer by training, he has developed many computer systems in railway control and other industrial applications and a wide range of software tools for embedded systems. Networking projects included Bitup, a Bitbus emulation for the 80188 processor; data transfer protocols using Arcnet and Ethernet; and a full 801888-based remote-boot communications system using the simpler TCP/IP protocols (UDP and TFTP). Recent work has been in implementing embedded TCP/IP systems in aerospace, air quality, and video surveillance applications. In his spare time, Jeremy enjoys playing racquet sports, and is an accomplished amateur actor.





https://github.com/EmcraftSystems/u-boot.git
