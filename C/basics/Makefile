
# %.o: %.c: A pattern rule to compile .c files into .o files.
# $@: Represents the target name.
# $<: Represents the first prerequisite (source file).
# $^: Represents all prerequisites.

CC = gcc 
CFLAGS = -Wall -g 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = basic 

# find ant in string $(SRCS)
ifneq (,$(findstring ant,$(SRCS)))
	name="found"
else 
	name="not found"
endif 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 
	echo "ants $(name) in directory"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

list_c_files:
	echo "$(SRCS)"
 
replace_c_suffix:
	echo "$(OBJS)"

clean:
	rm -f $(OBJS) $(TARGET)

