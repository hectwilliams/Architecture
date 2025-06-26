CC = gcc 
CFLAGS = -Wall 
DEBUG = -g -O0 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main 

all: $(TARGET)
	lldb  $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG)  -c $< -o $@   -I./includes

clean:
	rm -f $(OBJS) $(TARGET)


