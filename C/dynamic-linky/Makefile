CC = gcc

CFLAGS = -Wall -g 
DYN_FLAGS = -fPIC
DYN_LIB_PREFIX = lib
DYN_LIB_EXT = .so 
DYN_LIB_SUBNAME = mylib
DYN_LIB_FILENAME = $(DYN_LIB_PREFIX)$(DYN_LIB_SUBNAME)$(DYN_LIB_EXT)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main 
LIB_DIR = ./lib
HEADER_DIR = ./includes

# point to library and header directory and compile a program using shared library  
$(TARGET):$(DYN_LIB_FILENAME)
	$(CC) main.c -L${LIB_DIR} -l$(DYN_LIB_SUBNAME) -o $(TARGET) -I${HEADER_DIR}

# link objects into shared library
$(DYN_LIB_FILENAME): $(filter-out main%,$(OBJS))  # filter pesky main.o
	mkdir -p lib includes;
	$(CC) -shared -o ${LIB_DIR}/$(DYN_LIB_FILENAME) $^;

# compile source w/flags creating object files 
%.o:%c
	$(CC) $(CFLAGS) -c  $(DYN_FLAGS) $< -o $@  

clean:
	rm -rf $(OBJS) $(LIB_DIR) *.so  $(TARGET)