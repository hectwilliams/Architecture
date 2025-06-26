
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
AR = ar
AR_FLAGS = rcs
COUNT=0


all: ${LIB}
	$(CC_++) -o $(TARGET) $(TARGET).cpp -L. -l$(LIB_NAME)  -I./includes

${LIB}: $(filter-out main.o,$(OBJS_CPP))
	$(CC) -c basic_.c -o basic_.o 
	$(AR) $(AR_FLAGS) $(LIB) $^ basic_.o 

%.o: %.cpp
	$(CC_++) $(CFLAGS) -c $< -o $@  

clean:
	rm -f $(OBJS_CPP) $(TARGET) $(LIB)

