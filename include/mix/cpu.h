#ifndef MIX_CPU_H
#define MIX_CPU_H
#include <stdint.h>

typedef int8_t byte;
typedef struct {
  uint8_t sign;
  uint8_t byte1;
  uint8_t byte2;
  uint8_t byte3;
  uint8_t byte4;
  uint8_t byte5;
} Word;

typedef enum {
  CMP_IND_E,
  CMP_IND_L,
  CMP_IND_G,
} CmpInd;

typedef struct{
  uint8_t byte1;
  uint8_t byte2;
} _rix;

struct MixCpu {
  uint8_t overflow_toggle;
  CmpInd ind;
  mixword ra;
  mixword rx;
  _rix ri[16]; 
};

typedef struct {

}

typedef enum {
  MIX_OPT_LDA = 
}

// sign bit: wasted bit: 5 bytes each 6 bits

#endif
