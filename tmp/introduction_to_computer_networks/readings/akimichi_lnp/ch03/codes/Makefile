CC = gcc
CFLAGS = -g -Wall
LDFLAGS =

SRCS = $(wildcard *.c) 
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TGTS = udprecv udpsend udpsend2 udprecv2 udpsend3 udpbcast udpgcast udpgrecv

all : $(TGTS)

# p.87 List 3-12
udpgrecv : udpgrecv.o

# p.86 List 3-11
udpgcast : udpgcast.o

# p.83 List 3-10
udpbcast : udpbcast.o

# p.81 List 3-9
udpsend3 : udpsend3.o

# p.80 List 3-8
udprecv2 : udprecv2.o

# p.78 List 3-7
udpsend2 : udpsend2.o

# p.76 List 3-6
udpsend : udpsend.o

# p.73 List 3-3
udprecv : udprecv.o
	$(CC) -o $@ $< $(LDFLAGS) 

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(wildcard *.o) $(TGTS)
