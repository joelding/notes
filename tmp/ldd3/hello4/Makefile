# command for SE510 platform with MIPS core
# make ARCH=mips CROSS_COMPILE=mipsel-linux- 

Q = @

ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
	obj-m := hello4.o
	hello4-objs := foo.o init.o
else
# Normal Makefile
# x86
#	KERNELDIR ?= /lib/modules/$(shell uname -r)/build

# cross compile
	KERNELDIR ?= /media/a003257/2TB/avm/se510/AVerCasterHDDuet/RT288x_SDK/source/linux-2.6.21.x
	PWD := $(shell pwd)

default:
	$(Q)$(MAKE) -C $(KERNELDIR) M=$(PWD) modules 
endif

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers

depend .depend dep:
	$(Q)$(CC) $(CFLAGS) -M *.c > .depend

ifeq (.depend,$(wildcard .depend))
include .depend
endif
