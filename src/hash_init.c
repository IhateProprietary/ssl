/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:51:20 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 20:24:27 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "global.h"
#include "md5.h"
#include "sha2.h"
#include "ft_getopt_long.h"

ctx_t		g_sha256_h0 = {
	.b = {0, 0},
	.buf = {0},
	.r = {
		0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
		0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
	},
	.opt = 0,
	.hashsize = 32,
	.update = sha2update,
	.decode = sha2decode,
	.encode = sha2encode,
	.final = sha2final,
	.hashname = "SHA256",
	.context = 0
};

ctx_t		g_sha224_h0 = {
	.b = {0, 0},
	.buf = {0},
	.r = {
		0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
		0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4
	},
	.opt = 0,
	.hashsize = 28,
	.update = sha2update,
	.decode = sha2decode,
	.encode = sha2encode,
	.final = sha2final,
	.hashname = "SHA224",
	.context = 0
};

ctx_t		g_md5_h0 = {
	.b = {0, 0},
	.buf = {0},
	.r = {
		0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476,
		0x00000000, 0x00000000, 0x00000000, 0x00000000
	},
	.opt = 0,
	.hashsize = 16,
	.update = md5update,
	.decode = md5decode,
	.encode = md5encode,
	.final = md5final,
	.hashname = "MD5",
	.context = 0
};

uint32_t	hash_string(char *str)
{
	uint32_t	hash;

	hash = 85206151;
	while (*str)
	{
		hash ^= *str++ * 85206151;
		hash += 85206151;
	}
	return (hash);
}

ctx_t		*setcmd(char **av, ctx_t *ctx)
{
	uint32_t	hash;

	hash = hash_string(av[0]);
	if (hash == 0x7b2cc030)
	{
		ft_memcpy(ctx, &g_sha256_h0, sizeof(*ctx));
		return (&g_sha256_h0);
	}
	else if (hash == 0xc210c48b)
	{
		ft_memcpy(ctx, &g_sha224_h0, sizeof(*ctx));
		return (&g_sha224_h0);
	}
	else if (hash == 0xc78645bc)
	{
		ft_memcpy(ctx, &g_md5_h0, sizeof(*ctx));
		return (&g_md5_h0);
	}
	return (0);
}

ctx_t		*hash_init(int ac, char **av, ctx_t *ctx)
{
	static struct s_options	opt[] = {
		{"string", req_arg, 0, 's'}, {"verbose", no_arg, 0, 'p'},
		{"quiet", no_arg, 0, 'q'}, {"reverse", no_arg, 0, 'r'},
		{0, 0, 0, 0}
	};
	int						flag;
	ctx_t					*algo;

	if ((algo = setcmd(av, ctx)) == 0)
		error(av[0], CMD_ERROR);
	while ((flag = ft_getopt_long(ac, av, "spqr", opt)) > -1)
	{
		if (flag == '?')
			error(0, OPT_ERROR);
		else if (flag == 's')
			shash_digest(ctx, g_optarg_, algo);
		else if (flag == 'p')
			hash_stdin(ctx, STDOUT, algo);
		else if (flag == 'q')
			ctx->opt |= QUIET;
		else if (flag == 'r')
			ctx->opt |= REVERSE;
	}
	return (algo);
}
