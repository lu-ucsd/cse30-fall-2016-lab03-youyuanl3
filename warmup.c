#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

unsigned int *char_freqs(FILE *fp){
  /* get the frequence count of each character in the file */
  unsigned int * arr = calloc(256, sizeof(unsigned int));
  int ch;

  if (fp == NULL)  // return null when fp is null
    return NULL;

  while ((ch = fgetc(fp)) != EOF)  // traverse the file to count frequence
    arr[ch]++;

  return arr;
}


int reorder_bytes(int num){
  /* reverse the endianness of the number */
  int byte0 = (num & 0xFF) << 24;  // get 4 bytes of the number
  int byte1 = (num & 0xFF00) << 8;
  int byte2 = (num >> 8) & 0xFF00;
  int byte3 = (num >> 24) & 0xFF;

  int val = byte0 + byte1 + byte2 + byte3;  // reverse the order of bytes

  return val;
}
