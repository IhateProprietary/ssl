/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sslbasic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:40:16 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 18:53:47 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "global.h"
#include "libft.h"
#include "ft_printf.h"

void	concat__(ctx_t *ctx, char *buf, ssize_t size)
{
	char	*tmp;
	char	*new_;
	size_t	sum;

	tmp = ctx->s_;
	sum = ctx->len + size;
	if ((new_ = malloc(sum)) == 0)
		return ;
	ft_memcpy(new_, tmp, ctx->len);
	ft_memcpy(new_ + ctx->len, buf, size);
	ctx->len = sum;
	ctx->s_ = new_;
	free(tmp);
}

void	fhash_digest(ctx_t *ctx, int fd)
{
	ssize_t	ret;
	char	buf[1024];

	while ((ret = read(fd, buf, 1024)) > 0)
	{
		if (ctx->opt & STDOUT && fd == STDIN_FILENO)
			concat__(ctx, buf, ret);
		ctx->update(ctx, (uint8_t*)buf, ret);
	}
	ctx->final(ctx);
}

void	shash_digest(ctx_t *ctx, char *s)
{
	ctx->opt |= SUMARGV;
	ctx->update(ctx, (uint8_t *)s, ft_strlen(s));
	ctx->final(ctx);
	hash_result(ctx, s);
	ctx->opt &= ~SUMARGV;
}

void	print(uint8_t *digest, size_t dsize)
{
	int	i;

	i = 0;
	while (i < dsize)
		ft_dprintf(1, "%02x", digest[i++]);
}

void	hash_result(ctx_t *ctx, char *context)
{
	uint8_t	digest[32];

	ctx->encode(digest, ctx->r, ctx->hashsize);
	if (ctx->opt & STDOUT && !(ctx->opt & QUIET))
	{
		write(STDOUT_FILENO, ctx->s_, ctx->len);
		free(ctx->s_);
		ctx->s_ = 0;
	}
	else
		ft_dprintf(1, ctx->opt & SUMARGV ? "%s (\"%s\") = " : "%s(%s) = ",
			ctx->hashname, context);
	print(digest, ctx->hashsize);
	if (ctx->opt & REVERSE)
		ft_dprintf(1, ctx->opt & SUMARGV ? " \"%s\"" : " %s", context);
	ft_dprintf(1, "\n");
}
