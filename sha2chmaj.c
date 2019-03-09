#include <stdint.h>
#include "sha2.h"

uint32_t sha2ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ (~(x) & (z)));
}

uint32_t sha2maj(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}
