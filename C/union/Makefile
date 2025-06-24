
# %.o: %.c: A pattern rule to compile .c files into .o files.
# $@: Represents the target name.
# $<: Represents the first prerequisite (source file).
# $^: Represents all prerequisites.

CC = gcc 
CFLAGS = -Wall -g 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@   -I./includes


clean:
	rm -f $(OBJS) $(TARGET)

