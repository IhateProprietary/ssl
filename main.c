#include "md5.h"
#include <unistd.h>

int		main(void)
{
	char buf[1024];
	char digest[16];
	md5ctx_t ctx;
	ssize_t ret;

	md5init(&ctx);
	while ((ret = read(0, buf, 1024)) > 0)
		md5update(&ctx, (uint8_t*)buf, ret);
	md5final((uint8_t*)digest, &ctx);
	for (int i = 0; i < 16; i++)
	{
		printf("%hhx", digest[i]);
	}
	printf("\n");
}
