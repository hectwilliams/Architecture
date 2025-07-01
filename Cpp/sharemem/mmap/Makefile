CC+ = g++ 
FLAGS = -Wall -g 
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJS_FILTERED = $(filter-out main.o, $(OBJS)) # concat all object files related to 'fictictious' library together

TARGET = main

LIB_PREFIX = lib
LIB_NAME = classy_util
LIB_EXT = .a
LIB = $(LIB_PREFIX)$(LIB_NAME)$(LIB_EXT)
LIB_PATH = $(LIB)
AR = ar
AR_FLAGS = rcs

all: $(LIB)
	$(CC+) -o $(TARGET) $(TARGET).cpp -L. -l$(LIB_NAME)  -I./includes

${LIB}: $(OBJS_FILTERED)
	$(AR) $(AR_FLAGS) $(LIB_PATH) $^ 

%.o: %.cpp
	$(CC+) $(FLAGS)  -c $< -o $@ -I./includes

clean:
	rm -f $(OBJS) $(TARGET) $(LIB_PATH)