#include <iostream>
#include "rabbit.h"

void print_pos(int *x, int *y) {
  std::cout << "x="<< *x << " "<< "y=" <<*y<< '\n';
}

void moveup (int *x, int *y) {
  (*y)++;  
}

void moveleft (int *x, int *y) {
  (*x)--;
}

void moveright (int *x, int *y) {
  (*x)++;
}

void movedown (int *x, int *y) {
  (*y)--;
}
