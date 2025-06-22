
CC = gcc 
CFLAGS = -Wall -g 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main 
HEADER_PATH = ./my_includes 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -I /foo

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@ 

list_c_files:
	echo "$(SRCS)"
 
replace_c_suffix:
	echo "$(OBJS)"

clean:
	rm -f $(OBJS) $(TARGET)
