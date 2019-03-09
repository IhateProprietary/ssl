#include <stdint.h>
#include <string.h>
#include "sha2.h"

void sha2update(sha2ctx_t *ctx, uint8_t *input, uint32_t size)
{
	uint32_t avail;
	uint32_t used;
	uint32_t lo;

	lo = ctx->b[1];
	if ((ctx->b[1] = (lo + size) & 0x1fffffff) < lo)
		ctx->b[0]++;
	ctx->b[0] += size >> 29;
	used = lo & 0x3f;
	avail = 64 - used;
	if (size >= avail)
	{
		memcpy(&ctx->buf[used], input, avail);
		sha2transform(ctx->r, ctx->buf);
		while (avail + 63 < size)
		{
			sha2transform(ctx->r, input + avail);
			avail += 64;
		}
		used = 0;
	}
	else
		avail = 0;
	memcpy(ctx->buf + used, input + avail, size - avail);
}
