/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:11:32 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 18:54:28 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include "global.h"
#include "sha2.h"
#include "md5.h"

void	sha2update(ctx_t *ctx, uint8_t *input, uint64_t size)
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
		ft_memcpy(&ctx->buf[used], input, avail);
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
	ft_memcpy(ctx->buf + used, input + avail, size - avail);
}

void	md5update(ctx_t *ctx, uint8_t *input, uint64_t size)
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
		ft_memcpy(&ctx->buf[used], input, avail);
		md5transform(ctx->r, ctx->buf);
		while (avail + 63 < size)
		{
			md5transform(ctx->r, input + avail);
			avail += 64;
		}
		used = 0;
	}
	else
		avail = 0;
	ft_memcpy(ctx->buf + used, input + avail, size - avail);
}
