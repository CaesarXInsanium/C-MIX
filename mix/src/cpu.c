#include "mix/cpu.h"
#include "mix/byte.h"
#include "mix/opts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fprint_word(FILE *stream, Word a) {
  fprintf(stream, "Sign: %d ", a.sign);
  fprintf(stream, "A: %u ", a.a);
  fprintf(stream, "B: %u ", a.b);
  fprintf(stream, "C: %u ", a.c);
  fprintf(stream, "D: %u ", a.d);
  fprintf(stream, "E: %u ", a.e);
  fprintf(stream, "\n");
}

void process_instruction(MixCpu *cpu, Word word) {
  byte opt_code = word.e;
  byte mod = word.d;
  byte index = word.c;
  Pair address = {.sign = word.sign, .a = word.a, .b = word.b};

  switch (opt_code) {
  case MIX_OPT_LDA:
    puts("LDA Instruction");
    cpu->ra = cpu->memory[address];
  default:
    puts("Invalid Instruction");
    exit(EXIT_FAILURE);
  }
}

void 

void init_cpu(MixCpu *cpu) { memset(cpu, 0, sizeof(MixCpu)); }

void cpu_memory(MixCpu *cpu, Word *mem) { cpu->memory = mem; }
