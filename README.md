# MIX

My implementation of Knuth's MIX computer. I hope I can make this work. It has begun
to find out it is a pain in the Ass to keep up with the 6-bit a byte
and 5 bytes a word, with a sign bit. It can fit inside a 32-bit integer but
doing so would be prone to bugs since I am not good with bit-shifting stuff.

Instead, I will be designing my CPU, instruction set and architecture. It will
attempt to mimic the MIX style as much as possible. No, I will not use MMIX
because I am stupid.

## CPU

Big Endian Design

- `Opt`: 4 bits, Opt Code or section of code
- `Byte`: 8-bits. Dead simple.
- `Word`: 4 bytes, leading bit is sign bit.

## Instruction Codes

- 0x10: LDA
- 0x0f: LDX
