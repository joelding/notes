CC = gcc
CFLAGS = -g -Wall
LDFLAGS =

SRCS = $(wildcard *.c) 
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TGTS = ex01 ssrv scli ssrv2 scli2 

all : $(TGTS)

scli2 : scli2.o
scli : scli.o
ssrv2 : ssrv2.o
ssrv : ssrv.o
	$(CC) -o $@ $< $(LDFLAGS) 

# first piece of code to try socket()
ex01 : ex01.o
	$(CC) -o $@ $< $(LDFLAGS) 

.c.o :
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(wildcard *.o) $(TGTS)
