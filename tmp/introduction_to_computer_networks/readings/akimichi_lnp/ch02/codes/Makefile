CC = gcc
CFLAGS = -g -Wall
LDFLAGS =

SRCS = $(wildcard *.c) 
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TGTS = ex01 ex02 ssrv scli ssrv2 scli2 perror perror2 nobind getadrinfo getip ssrv3 sftp_srv sftp_cli http_srv http_cli

all : $(TGTS)

http_srv : http_srv.o
http_cli : http_cli.o

# sftp_cli : transmit a file to a master
sftp_srv : sftp_srv.o
# sftp_srv : receive a file from a client
sftp_srv : sftp_srv.o

# use getaddrinfo before bind
ssrv3 : ssrv3.o

# getadrinfo.c : practicing getaddrinfo/gethostbyname
getadrinfo : getadrinfo.o

# apply perror()
perror2 : perror2.o
perror : perror.o

# add loops to lengthen the test
scli2 : scli2.o
ssrv2 : ssrv2.o

# first server/client program
scli : scli.o
ssrv : ssrv.o
	$(CC) -o $@ $< $(LDFLAGS) 

# second test originated from ex01
# Socket may return a file descriptor 0.
ex02 : ex02.o
	$(CC) -o $@ $< $(LDFLAGS) 

# first piece of code to try socket()
ex01 : ex01.o
	$(CC) -o $@ $< $(LDFLAGS) 

.c.o :
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(wildcard *.o) $(TGTS)
