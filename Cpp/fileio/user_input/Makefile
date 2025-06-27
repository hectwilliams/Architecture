CC = g++ 
FLAGS = -Wall -g 
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all:$(filter-out main.o, $(OBJS))  
	$(CC) -o $(TARGET) $(TARGET).cpp -I./includes

%.o:%.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main