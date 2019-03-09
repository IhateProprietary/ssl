#include "sha2.h"

void sha2init(sha2ctx_t *ctx)
{
	ctx->b[1] = 0;
	ctx->b[0] = 0;
	ctx->r[0] = 0x6a09e667;
	ctx->r[1] = 0xbb67ae85;
	ctx->r[2] = 0x3c6ef372;
	ctx->r[3] = 0xa54ff53a;
	ctx->r[4] = 0x510e527f;
	ctx->r[5] = 0x9b05688c;
	ctx->r[6] = 0x1f83d9ab;
	ctx->r[7] = 0x5be0cd19;
}
