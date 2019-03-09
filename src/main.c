//#include "md5.h"
#include <unistd.h>
#include "sha2.h"

uint32_t sha224_h0[8] =
            {0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
             0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4};

uint32_t sha256_h0[8] =
            {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
			 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};

int		main()
{
	char buf[1024];
	char digest[32];
	sha2ctx_t ctx;
	ssize_t ret;

	sha2init(&ctx, sha224_h0);
	while ((ret = read(0, buf, 1024)) > 0)
		sha2update(&ctx, (uint8_t*)buf, ret);
	sha2final((uint8_t*)digest, &ctx, 28);
	for (int i = 0; i < 28; i++)
	{
		printf("%02hhx", digest[i]);
	}
	printf("\n");
}
