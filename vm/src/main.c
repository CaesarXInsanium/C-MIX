#include "mix/cpu.h"
#include "mix/opts.h"
#include "mix/version.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

#define BYTES(x) (show_bytes((byte_pointer)&x, sizeof(x)))

int main(void) {
  puts("Running the VM");
  printf("libmix version %d\n", MIX_VERSION);
  puts("Beginning Testing");

  Word w;
  memset(&w, 0, sizeof(Word));
  printf("Size: %lu\n", sizeof(Word));
  BYTES(w);
  printf("Changing Value to: %u\n", 30);
  w.a = 30;
  BYTES(w);
  fprint_word(stdout, w);
  puts("Flipping Sign");
  w.sign = 1;
  BYTES(w);
  fprint_word(stdout, w);
  for (size_t i = 0; i < 100; i++) {
    w.d = i;
    BYTES(w);
    fprint_word(stdout, w);
  }

  puts("Cpu");

  MixCpu c;
  printf("sizeof(CPU) = %lu\n", sizeof(MixCpu));
  BYTES(c);
}
