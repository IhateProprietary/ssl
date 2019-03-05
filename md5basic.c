#include <stdint.h>

uint32_t	f(uint32_t x, uint32_t y, uint32_t z)
{
	return ((z) ^ ((x) & ((y) ^ (z))));
}

uint32_t	g(uint32_t x, uint32_t y, uint32_t z)
{
	return ((y) ^ ((z) & ((x) ^ (y))));
}

uint32_t	h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint64_t	i(uint64_t x, uint64_t y, uint64_t z)
{
	return (y ^ (x | ~z));
}
