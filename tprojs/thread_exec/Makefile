CC = gcc
RM = rm
CFLAGS = -Wall
LDFLAGS = -lpthread
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TARGET = thread_exec

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $<



$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) -f *.o $(TARGET)
