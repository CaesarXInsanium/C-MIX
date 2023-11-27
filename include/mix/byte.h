#ifndef MIX_BYTE_H
#define MIX_BYTE_H
#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;

typedef struct {
  byte sign ;
  byte bits[5];
} Word;

#define BIT_A(x) ((word).bits[0])

typedef struct {
  byte sign:1;
  byte a:6;
  byte b:6;
} Pair;

uint32_t unsigned_pair_value(Pair p);

void fprint_word(FILE *stream, Word a);
#endif
