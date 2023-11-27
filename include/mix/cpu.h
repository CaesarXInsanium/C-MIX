#ifndef MIX_CPU_H
#define MIX_CPU_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mix/byte.h"

#define MAX_MEMORY_SIZE 4000


typedef union {
  uint32_t ints;
  Word word;
} Wordu;

typedef enum {
  CMP_IND_E,
  CMP_IND_L,
  CMP_IND_G,
} CmpInd;

typedef struct {

  // flags
  CmpInd condition_flag:7;
  unsigned int overflow_flag: 1;

  // general purpose registers

  Word rj; // jump address
  Word ra;
  Word rx;
  Pair ri[16];
  
  //io stuff
  Pair ui[20];


  // pointer to memory
  Word *memory;
} MixCpu;

void process_instruction(MixCpu *cpu, Word word);

void init_cpu(MixCpu *cpu);
void cpu_memory(MixCpu *cpu, Word *mem);
void fetch_ins(MixCpu *cpu);
void execute(MixCpu *cpu);
void cycle(MixCpu *cpu);
void run(MixCpu *cpu);

#endif
