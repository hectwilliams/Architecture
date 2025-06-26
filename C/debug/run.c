#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Record {
  int a;
};

void hello_world () {
  printf("[RUN SOURCE] hello world\n");
}

int main () {

  struct Record r = {.a =100};

  int count = 0;

  for(int i = 0; i < 5; i++) {
    
    count += 1;

  }

  printf("Counter [%d]\n", count);
  
  assert(1);
  
  hello_world(); 
  
  assert(&r );

  return 0;
}
