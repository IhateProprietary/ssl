#include "sha2.h"

void sha2init(sha2ctx_t *ctx, uint32_t *init)
{
	ctx->b[1] = 0;
	ctx->b[0] = 0;
	ctx->r[0] = init[0];
	ctx->r[1] = init[1];
	ctx->r[2] = init[2];
	ctx->r[3] = init[3];
	ctx->r[4] = init[4];
	ctx->r[5] = init[5];
	ctx->r[6] = init[6];
	ctx->r[7] = init[7];
}
