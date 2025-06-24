#include <stdio.h>
#include <string.h>
#include <run.h>

void run_two_packed() {

    unsigned size = sizeof(TwoBytePackedStruct);
    void *ptr;

    printf("size of packed struct %d bytes \n", size);

    TwoBytePackedStruct p = {
    .a = 'A',
    .b = 'B'
    };

    ptr = &p;

    for (int i =0; i < size; i++) {
      
      printf("byte address:\t[%p]\n", (ptr+ i) );

      printf("byte-data:\t[%x]\n", *(char *)(ptr+ i) );

    }

}

/*
    fill buffer location with dashes 
*/
void dash_fill(void *buffer, int len) {

    char scratchpad[len ];
    
    int i = 0;
    for ( ; i < len; i++) {
        
        scratchpad[i] = '-';

    }

    memcpy(buffer, scratchpad, len);

}

void run_six_packed() {
    
    void *ptr;
    unsigned size = sizeof(SixBytePackedStruct);
    char pad[size + 1 ]; // null terminated moved to index 6

    SixBytePackedStruct p = {

        .a = 'C',

        .b = "©©", // © requires 2 bytes per special character 
        
        .c = 'F'

    };

    ptr = &p;
    
    printf("Number of bytes %d\n", size);

    memcpy(pad, ptr, size);
    printf("full packed memory data %s\n", pad);

    // Fill buffer with dashes buffer
    dash_fill(pad, size);

    // read 'a' attribute 
    memcpy(pad, ptr, 1);
    printf("pad=[%s]\n",  pad );

    dash_fill(pad, size);

    // read 'b' attribute 
    memcpy(pad, ptr + 1, 4);
    printf("pad=[%s]\n",  pad );

    {
        // hex representation of .b attribute 
        void *tmp_pad = malloc( 4* sizeof(char) ); 
        memcpy(tmp_pad, ptr + 1, 4);
        printf("str reprensentation of .b =[%s]\n", (char *)tmp_pad);
        printf("hex reprensentation of .b =[0x%X]\n",  *((int *)tmp_pad)  ); // cast void pointer 
        free(tmp_pad);
        
    }

    dash_fill(pad, size);

    // read 'c' attribute 
    memcpy(pad, ptr + 5, 1);
    printf("pad=[%s]\n",  pad );

}

void run_six_packed_TwoByteAligned () {
    
    void *ptr; 

    unsigned size = sizeof(SixBytePackedPragmaStruct);

    char pad[ size + 1 ]; // null terminated moved to index 6
    void *tmp_2bytes_pad = malloc( 2 * sizeof(char) ); 
    void *tmp_4bytes_pad = malloc( 4 * sizeof(char) ); 
    
    pad[size] = '\0';

    SixBytePackedPragmaStruct p = {

        .a = 'C', 
        
        .b = 0xA9C2A9C2, 
        
        .c = 'F'

    };

    ptr = &p;

    printf("\nnumber of bytes %d\n", size);
    
    dash_fill(pad, size);
    memcpy(pad, ptr , 2);
    memcpy(tmp_2bytes_pad, ptr , 2);
    printf("str reprensentation of .a [%s]\n", pad );
    printf("hex reprensentation of .a [0x%X]\n", *((int *)tmp_2bytes_pad) );
    
    dash_fill(pad, size);
    memcpy(pad, ptr + 2, 4);
    memcpy(tmp_4bytes_pad, ptr + 2 , 4);
    printf("str reprensentation of .b [%s]\n", pad );
    printf("hex reprensentation of .b [0x%X]\n", *((int *)tmp_4bytes_pad) );

    dash_fill(pad, size);
    memcpy(pad, ptr + 6, 4);
    memcpy(tmp_2bytes_pad, ptr + 6 , 2);
    printf("str reprensentation of .c [%s]\n", pad );
    printf("hex reprensentation of .c [0x%X]\n", *((int *)tmp_2bytes_pad) );
    
}

void run_unpacked () {

    void *ptr; 

    unsigned size = 4; // byte aligned

    char pad[ size + 1 ]; // null terminated moved to index 6
    
    pad[size] = '\0';

    TwelveByteUnpackedStruct p = {

        .a = 'C', 
        
        .b = 0xA9C2A9C2, 
        
        .c = 'F'

    };

    ptr = &p;

    printf("\nnumber of bytes %d\n", size);
    

    memcpy(pad, ptr , 4);
    printf("str reprensentation of .a [%s]\n", pad );
    printf("hex reprensentation of .a [0x%x]\n", *((int *)pad) );

    memcpy(pad, ptr + 4, 4);
    printf("str reprensentation of .a [%s]\n", pad );
    printf("hex reprensentation of .a [0x%x]\n", *((int *)pad) );

    memcpy(pad, ptr + 8, 4);
    printf("str reprensentation of .a [%s]\n", pad );
    printf("hex reprensentation of .a [0x%x]\n", *((int *)pad) );

}

int main() {
    
    run_unpacked();
    
}