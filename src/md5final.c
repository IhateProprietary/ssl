#include <stdint.h>
#include <string.h>
#include "md5.h"

void md5final(uint8_t *digest, md5ctx_t *ctx)
{
	static uint8_t	padding[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	uint8_t			bits[8];
	uint32_t		index;
	uint32_t		padlen;

	index = ctx->b[0] & 0x3f;
	ctx->b[0] <<= 3;
	encode(bits, ctx->b, 8);
	ctx->b[0] >>= 3;
	padlen = (index < 56) ? (56 - index) : (120 - index);
	md5update(ctx, padding, padlen);
	md5update(ctx, bits, 8);
	encode(digest, ctx->r, 16);
}
