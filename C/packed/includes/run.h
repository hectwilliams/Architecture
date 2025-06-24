#include <stdlib.h>

#ifndef PACKED_EX_H
#define PACKED_EX_H

typedef struct __attribute__((packed))  { //  byte aligned 
  char a;
  char b;
}TwoBytePackedStruct;

typedef struct  __attribute__((packed)) { //  byte aligned 
  char a;     // 1b
  char b[4];     //4b 
  char c;     // 1b
} SixBytePackedStruct;

#pragma pack(2) // 2 byte aligned 
typedef struct {
  char a; // 1 byte ( effective 2 bytes)
  int  b; // 4 bytes 
  char c; // 1 bytes ( effective 2 bytes)
} SixBytePackedPragmaStruct;
#pragma pack()

typedef struct { //  padding 
  char a; // 1 byte + 3 byte pad  ( 4 bytes )
  int b;  // 4 bytes 
  char c;  // 1 bytes  + 3 byte pad ( 4 bytes )
} TwelveByteUnpackedStruct;

void run_two_packed();
void run_six_packed();
void run_six_packed_TwoByteAligned();
void run_unpacked();

#endif 