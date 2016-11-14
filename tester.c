/**
 * THIS FILE MAY BE USED FOR TEST CODE. IT WILL NOT BE COLLECTED
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"

char decodeChar(char * b);
void binaryToText(FILE * in, FILE * out);

int main(int argc, char *argv[]){
  FILE * in = fopen("bin_astley.txt", "r");
  FILE * out = fopen("testtext.txt", "w");
  binaryToText(in, out);
  fclose(in);
  fclose(out);
  return 0;
}
