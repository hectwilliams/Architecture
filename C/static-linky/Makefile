CC = gcc 
ARCHIVE = ar 
ARCHIVE_OPTIONS = rcsv # r-insert files, c-create archive, s - create object file-index
HEADER_DIR = ./include/
ARCHIVE_FILENAME_EXT= .a
ARCHIVE_FILENAME_PREFIX= lib
ARCHIVE_NAME = mylib
ARCHIVE_FILENAME = $(ARCHIVE_FILENAME_PREFIX)mylib$(ARCHIVE_FILENAME_EXT) # -libmylib
ARCHIVE_DIR = ./lib
CFLAGS = -Wall -g 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o) 
TARGET = luffy
FILTERED_OBJS = $(patsubst luffy%,,$(OBJS))   
# FILTERED_OBJS = $(subst luffy.o,, $(OBJS))   

all: $(TARGET)

$(TARGET):$(ARCHIVE_FILENAME)
	$(CC) -I$(HEADER_DIR) $(CFLAGS) -o $@ luffy.c -L$(ARCHIVE_DIR) -l$(ARCHIVE_NAME) 

$(ARCHIVE_FILENAME): $(FILTERED_OBJS)
	$(ARCHIVE) $(ARCHIVE_OPTIONS) $(ARCHIVE_FILENAME) $(FILTERED_OBJS) 
	mkdir -p lib include
	mv $(ARCHIVE_FILENAME)$(ARCHIVE_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(TARGET) 
	rm -rf lib 
