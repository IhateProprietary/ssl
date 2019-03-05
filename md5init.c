#include "md5.h"

void	md5init(md5ctx_t *ctx)
{
	ctx->b[0] = 0;
	ctx->b[1] = 0;
	ctx->r[0] = 0x67452301;
	ctx->r[1] = 0xefcdab89;
	ctx->r[2] = 0x98badcfe;
	ctx->r[3] = 0x10325476;
}
