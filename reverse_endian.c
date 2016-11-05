#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(int argc, char** argv){
  /* reverse the endianness of each input integer and output them */
  FILE * in;
  FILE * out;
  int num;

  if (argc != 3)  // incorrect number of arguments
    return 0;

  in = fopen(argv[1], "rb");
  out = fopen(argv[2], "wb");
  if (in == NULL)  // invalid argument
    return 0;

  // read input integers, reorder each of them, and output them
  while (fread(&num, sizeof(int), 1, in) == 1) {
    num = reorder_bytes(num);
    fwrite(&num, sizeof(int), 1, out);
  }

  fclose(in);
  fclose(out);
  return 0;
}
