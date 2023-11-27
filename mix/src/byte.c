#include <stdio.h>
#include <stdint.h>
#include "mix/byte.h"

uint32_t unsigned_pair_value(Pair p){
  uint8_t a = p.b;
  return (uint32_t)a;
}
