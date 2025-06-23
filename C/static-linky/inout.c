#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MENU_SIZE 4
#define STR_LEN  100

const char InOutItems[MENU_SIZE][STR_LEN] = {
  "Burgers",
  "Fries",
  "Drinks",
  "Fries"
};

typedef struct {
  int size;
  int str_len;  
  const char  * items;
  float avg_price;
} InOutMenu;

const InOutMenu int_out_menu = {
  .size = MENU_SIZE,
  .str_len = STR_LEN,
  .avg_price = 13.34f,
  .items = (const char   *)InOutItems 
};

void bestBurger_inout() {
  
  char buffer[int_out_menu.str_len];
  
  printf("inout is the best burger joint.\n We sell the following:\n");

  for (int i = 0; i < int_out_menu.size; i++) {

    memcpy(buffer,  int_out_menu.items+ i * int_out_menu.str_len, int_out_menu.str_len);

    printf("%s\n", buffer);
    
  }

}