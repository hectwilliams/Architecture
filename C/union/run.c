#include <stdio.h>
#include <string.h>
#include <run.h>

int main() {
  
    union V1 v1;
    void *ptr;
    int ret = snprintf(v1.a_8x4_char , 4, "©AB"); // © - 0xA9 A - 0xA  '\0' (© occupies 2 bytes, A occupues 1 byte , B is overwritten by '\0')
    
    printf("bytes written --> %d\n", ret); // program writes to memory space, system will add lasting changes (e,g, truncating and writing null terminator)

    // using void ptr
    ptr = v1.a_8x4_char;
    printf("byte chars --> x%s\n", (char *)ptr);

    ptr = v1.a_8x4u;
    printf(" unsigned char 1st byte 0x%hhu\n", *(u_int8_t*)ptr  ); // // signed char hhu
    printf(" unsigned char 2nd byte 0x%hhu\n", *(u_int8_t*)(ptr + 1)  );
    printf(" unsigned char 3rd byte 0x%hhu\n", *(u_int8_t*)(ptr + 2)  );
    printf(" unsigned char 4th byte 0x%hhu\n", *(u_int8_t*)(ptr + 3)  );

    ptr = v1.a_8x4i;
    printf(" signed char 1st byte 0x%hhd\n", *(int8_t*)ptr  );  // signed char hhn
    printf(" signed char 2nd byte 0x%hhd\n", *(int8_t*)(ptr + 1)  );
    printf(" signed char 3rd byte 0x%hhd\n", *(int8_t*)(ptr + 2)  );
    printf(" signed char 4th byte 0x%hhd\n", *(int8_t*)(ptr + 3)  );

}