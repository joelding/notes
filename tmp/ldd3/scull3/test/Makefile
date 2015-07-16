TARGET = test

all: $(TARGET)

CC = mipsel-linux-gcc
INCLUDES = -I/media/a003257/2TB/avm/se510b/AVerCasterHDDuet/toolchain-rt3883/buildroot-gcc342/include/ 
CFLAGS = -g -O2 -Wall

$(TARGET): $(TARGET).c
	$(CC) $(TARGET).c $(INCLUDES) -o $(TARGET)

clean:
	rm -f $(TARGET)
