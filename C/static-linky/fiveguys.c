#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MENU_SIZE  5
#define STR_LEN 100

const char FiveGuysItems[MENU_SIZE][STR_LEN] = {
  "Burgers",
  "HotDogs",
  "Fries",
  "MilkShakes",
  "Drinks"
};

typedef struct {
  int size;
  int str_len;
  const char  * items;
  float avg_price;
} FiveGuysMenu;

const FiveGuysMenu five_guys_menu = {
  .size = MENU_SIZE,
  .str_len = STR_LEN,
  .avg_price = 11.34f,
  .items = ( const char   *)FiveGuysItems
};

void bestBurger_five_guys() {

  char buffer[five_guys_menu.str_len];

  printf("five guys is the best burger joint\n");

  for (int i = 0; i < five_guys_menu.size; i++) {

    memcpy(buffer,  five_guys_menu.items+ i * five_guys_menu.str_len, five_guys_menu.str_len);
    
    printf("%s\n", buffer);
    
  }

}