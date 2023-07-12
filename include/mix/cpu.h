#ifndef MIX_CPU_H
#define MIX_CPU_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 4000

// I love bit fields
typedef struct {
  unsigned int sign : 1;
  unsigned int parity : 1;
  unsigned int a : 6;
  unsigned int b : 6;
  unsigned int c : 6;
  unsigned int d : 6;
  unsigned int e : 6;
} Word;

// 64 bit architecture for cpu
// one byte served as sign
// other seven are unreserved
typedef uint16_t word;
typedef uint8_t byte;

struct _word {
  uint8_t a;
  uint8_t b;
};

#define BYTE_POINTER(x) ((byte *)&x)

// big endian, get higher level opt from byte
// 0101 0101
#define OPT_HIGH(x) (x >> 4)
uint8_t opt_high(uint16_t x) {
  uint16_t g = x;
  uint8_t *h = BYTE_POINTER(g);
  return h[0];
}
uint8_t opt_low(uint16_t x) {
  uint16_t g = x;
  uint8_t *h = (uint8_t *)&g;
  return h[1];
}
#define OPT_LOW(x) ((x << 4) >> 4)

typedef union {
  struct _word word;
  word full;
} Wordu;
typedef enum {
  CMP_IND_E,
  CMP_IND_L,
  CMP_IND_G,
} CmpInd;

typedef struct {
  // general purpose registers

  uint32_t rj; // jump address
  word ra;
  word rx;
  uint8_t ri[16];
  CmpInd condition_flag;
  bool overflow_flag;
  uint8_t memory[MAX_MEMORY_SIZE];
} MixCpu;

#endif
