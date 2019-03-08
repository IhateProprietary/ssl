#include <stdint.h>
#include <string.h>
#include "md5.h"

void md5update(md5ctx_t *ctx, uint8_t *input, uint64_t size)
{
	uint32_t avail;
	uint32_t used;
	uint32_t lo;

	lo = ctx->b[0];
	if ((ctx->b[0] = (lo + size) & 0x1fffffff) < lo)
		ctx->b[1]++;
	ctx->b[1] += size >> 29;
	used = lo & 0x3f;
	avail = 64 - used;
	if (size >= avail)
	{
		memcpy(&ctx->buf[used], input, avail);
		md5transform(ctx->r, ctx->buf);
		while (avail < size)
		{
			md5transform(ctx->r, input + avail);
			avail += 64;
		}
		used = 0;
	}
	else
		avail = 0;
	memcpy(ctx->buf + used, input + avail, size - avail);
}
