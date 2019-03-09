//#include "md5.h"
#include <unistd.h>
#include "sha2.h"

int		main()
{
	char buf[1024];
	char digest[32];
	sha2ctx_t ctx;
	ssize_t ret;

	sha2init(&ctx);
	while ((ret = read(0, buf, 1024)) > 0)
		sha2update(&ctx, (uint8_t*)buf, ret);
	sha2final((uint8_t*)digest, &ctx, 32);
	for (int i = 0; i < 32; i++)
	{
		printf("%02hhx", digest[i]);
	}
	printf("\n");
}
