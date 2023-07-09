#include "mix/cpu.h"
#include "mix/opts.h"
#include "mix/version.h"
#include <stdint.h>
#include <stdio.h>

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

}
