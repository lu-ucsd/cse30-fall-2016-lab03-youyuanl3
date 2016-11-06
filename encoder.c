/**
 * ALL FUNCTION IMPLEMENTATIONS AND HELPER FUNCTIONS FOR ENCODER WILL BE IN THIS FILE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
/**
 *
 * This function takes a char c as input and returns a (6 character) array
 * that represents the 6 digit code for that character. This code is simply
 * the index of the char in the MAPPING array (represented in binary). 
 * You should use the REVERSE\_MAPPING array in this function to get 
 * the binary code for the character. REVERSE\_MAPPING array MUST be 
 * initialized with createReverseMapping(), prior to calling this function.
 *
 * @param c The input character to encode
 * @returns a six character array which encodes the index into ASCII binary
 */
char* encodeChar(char c){
  /* get the 6-digit binary code of the index of c in MAPPING */
  int index, pow, i;
  char * arr = malloc(6 * sizeof(char));

  createReverseMapping();
  index = REVERSE_MAPPING[(int)c];  // get the index of c in MAPPING

  // get the 6-digit binary representation of index
  for (i = 0, pow = 32; i < 6; i++, pow /= 2) {
    if (index >= pow) {
      index -= pow;
      arr[i] = '1';
    } else
      arr[i] = '0';
  }

  return arr;
}

/**
 * Takes a char c and int bit (should be either 0 or 1) and int index as input. 
 * Sets the bit at input index of c to be the input bit and returns the result.
 * The 0 index refers to the LSB, so for example, index 2 should 
 * set the 3rd least significant bit.
 * 
 * @param c the char to implant a bit into
 * @param bit the bit value to implant (0 or 1)
 * @param index the index to implant the bit into (0 is LSB)
 * @returns the char with bit b implanted into the input index
 */
char implantBit(char c, int bit, int index){
  /* implant the input bit at the input index of c */
  char mask = 1 << index;
  char val = c & (~mask);  // set the bit at the input index of c to be 0

  // set the bit at the input index of c to be 1 if the input bit is 1
  if (bit == 1)
    val += mask;

  return val;
}

/**
 * Takes a FILE handle in as input (corresponding to a regular ASCII
 * text file) and reads the file, char by char. Encodes each char into
 * a 6 character "binary" char array (by calling encodeChar).  The
 * resulting character arrays should be written to the output file
 * handle out
 *
 * @param in The input text file to read
 * @param out The output file, in ASCII encoded "binary"
 */
void textToBinary(FILE *in, FILE *out){
  /* get the 6-digit binary code of each input character and output then */
  int ch, i;
  char * arr;

  if (in == NULL)  // invalid input
    return;

  while ((ch = fgetc(in)) != EOF) {  // traverse all input characters
    arr = encodeChar(ch);
    for (i = 0; i < 6; i++) {  // output 6-digit binary code
      fputc(arr[i], out);
    }
    free(arr);
  }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" encoded file) and reads the file 1 char at a time. Each
 * char read will be an ASCII '0' or ASCII '1', and either 0 or 1 
 * will be implanted into randomized chars generated by rand()%256.
 *
 * If ASCII '0', then implant 0 into the bit at the input index 
 * of a randomized char . If ASCII '1', then implant 1 into the bit at 
 * the input index of the randomized char (by calling implantBit). 
 * Write the result into the output file handle out 
 * (Note: The least significant bit is in index 0)
 *
 * @param in The input file handle to read (ASCII encoded binary)
 * @param out The output file to write to
 * @param index the index of the bit where binary values should be implanted (0 is LSB)
 */
void binaryToCode(FILE *in, FILE *out, int index){
  /* implant each input character into a random char */
  char random;
  int ch;

  srand(1); //DO NOT REMOVE OR EDIT THIS LINE OF CODE

  if (in == NULL)  // invalid input
    return;

  while ((ch = fgetc(in)) != EOF) {  // traverse all input characters
    random = rand() % 256;
    if (ch == '0')
      fputc(implantBit(random, 0, index), out);
    else
      fputc(implantBit(random, 1, index), out);
  }
}

/**
 * Reads in a file from the specified input path and outputs a a binary encoding to
 * specified bin path and a fully encoded version to specified output path. 
 * This should simply open the necessary files and call the above helper 
 * functions in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the encoded ASCII binary output file
 * @param output the path to the encoded output file 
 * @param index The index of the bit where binary values should be implanted (0 is LSB)
 */
void encodeFile(char* input, char* bin, char* output, int index){
  /* transfer an input file to an encoded file */
  FILE * in = fopen(input, "a+");
  FILE * binary = fopen(bin, "a+");
  FILE * out = fopen(output, "a+");

  if (in == NULL)  // invalid input
    return;

  textToBinary(in, binary);
  binaryToCode(binary, out, index);

  fclose(in);
  fclose(binary);
  fclose(out);
}
