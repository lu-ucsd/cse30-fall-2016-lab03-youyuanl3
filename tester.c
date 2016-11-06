/**
 * THIS FILE MAY BE USED FOR TEST CODE. IT WILL NOT BE COLLECTED
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int main(int argc, char *argv[]){
  decodeFile("code_astley_3.txt", "testbin.txt", "testtext.txt", 3);
  return 0;
}
