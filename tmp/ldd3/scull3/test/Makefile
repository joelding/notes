TARGETS = test console setlevel

all: $(TARGETS)

CC = mipsel-linux-gcc
INCLUDES = -I /media/a003257/2TB/avm/se510b/AVerCasterHDDuet/toolchain-rt3883/buildroot-gcc342/include/ -I /media/a003257/2TB/avm/se510b/AVerCasterHDDuet/RT288x_SDK/source/linux-2.6.21.x/include
CFLAGS = -g -O2 -Wall

test: test.c
	$(CC) $(INCLUDES) $< -o $@

console: console.c
	$(CC) $(INCLUDES) $< -o $@

setlevel: setlevel.c
	$(CC) $(INCLUDES) $< -o $@

clean:
	rm -f $(TARGETS)
