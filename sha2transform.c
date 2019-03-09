#include <stdint.h>
#include <string.h>
#include "sha2.h"

void sha2swap(uint32_t *r, uint32_t *t)
{
	r[7] = r[6];
	r[6] = r[5];
	r[5] = r[4];
	r[4] = r[3] + t[0];
	r[3] = r[2];
	r[2] = r[1];
	r[1] = r[0];
	r[0] = t[0] + t[1];
}

void sha2loop(uint32_t *r, uint32_t *x)
{
	static const uint32_t	sin[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
		0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
		0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
		0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
		0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
		0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
		0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
		0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
	uint32_t				t[2];
	int						i;

	i = 0;
	while (i < 64)
	{
		t[0] = r[7] + sha2ep1(r[4]) + sha2ch(r[4],r[5],r[6]) + sin[i] + x[i];
		t[1] = sha2ep0(r[0]) + sha2maj(r[0],r[1],r[2]);
		sha2swap(r, t);
		i++;
		printf("0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
              t[0], t[1], r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7]);
	}
}

void sha2add(uint32_t *r, uint32_t *_r)
{
	r[0] += _r[0];
	r[1] += _r[1];
	r[2] += _r[2];
	r[3] += _r[3];
	r[4] += _r[4];
	r[5] += _r[5];
	r[6] += _r[6];
	r[7] += _r[7];
}

void sha2transform(uint32_t *r, uint8_t *block)
{
	uint32_t				x[64];
	uint32_t				_r[8];
	int						i;

	memcpy(_r, r, sizeof(_r));
	sha2decode(x, block, 64);
	i = 16;
	while (i < 64)
	{
		x[i] = sha2sig1(x[i - 2]) + x[i - 7] + sha2sig0(x[i - 15]) + x[i - 16];
		i++;
	}
	sha2loop(_r, x);
	sha2add(r, _r);
}
