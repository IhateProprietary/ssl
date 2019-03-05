#include <stdint.h>
#include "md5.h"

static inline uint64_t	rot(uint32_t x, uint32_t n) __attribute__((always_inline))
{
	return ((x << n) | (x >> (32 - n)));
}

void					magic(
	uint32_t (*t)(uint32_t, uint32_t, uint32_t),
	uint32_t *r,
	uint32_t *x
)
{
	r[0] += t(r[1], r[2], r[3]) + x[0] + x[2];
	r[0] = rot(r[0], x[1]);
	r[0] += r[1];
}
