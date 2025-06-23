
CC = gcc 
CFLAGS = -Wall -g 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main 
HEADER_PATH = ./my_includes 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(TARGET)
