CC = gcc
CC_++ = g++
CFLAGS = -Wall -g 
SRCS_CPP = $(wildcard *.cpp)
OBJS_CPP = $(SRCS_CPP:.cpp=.o)
SRCS_C = $(wildcard *.c)
OBJS_C = $(SRCS_C:.cpp=.o)

TARGET = main
LIB_PREFIX = lib
LIB_NAME = basic_util
LIB_EXT = .a
LIB = $(LIB_PREFIX)$(LIB_NAME)$(LIB_EXT)
LIB_PATH = ./lib/$(LIB)
AR = ar
AR_FLAGS = rcs
COUNT=0

SRCS_CPP = $(wildcard cpp_files/*.cpp)
OBJS_CPP = $(SRCS_CPP:.cpp=.o)

SRCS_C = $(wildcard c_files/*.c)
OBJS_C = $(SRCS_C:.c=.o)

OBJS = $(filter-out cpp_files/main.o, $(OBJS_CPP)) $(OBJS_C) # concat all object files related to 'fictictious' library together

# linky linky 
all: $(LIB)
	$(CC_++) -o $(TARGET) ./cpp_files/$(TARGET).cpp -L./lib -l$(LIB_NAME)  -I./includes

# create library from object files 
${LIB}: $(OBJS)
	$(AR) $(AR_FLAGS) $(LIB_PATH) $^ 

# compile all sources 
%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@ 
	
%.o: %.cpp
	$(CC_++) $(CFLAGS) -c $< -o $@  

clean:
	rm -f $(OBJS) $(TARGET) $(LIB_PATH)

