/*
  Static library linked to this source file.

  Libraries are typically used when the source generate data is calls on module(s)

  to ooperate on the source's data 
  
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inout.h>
#include <fiveguys.h>

int main() {

  printf("Should I eat fiveguys or inout?\n");
  
  bestBurger_five_guys();

  bestBurger_inout();


}