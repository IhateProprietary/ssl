/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:12:00 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 18:49:35 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "global.h"

void	sha2final(ctx_t *ctx)
{
	static uint8_t	padding[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	uint8_t			bits[8];
	uint32_t		index;
	uint32_t		padlen;

	index = ctx->b[1] & 0x3f;
	ctx->b[1] <<= 3;
	ctx->encode(bits, ctx->b, 8);
	ctx->b[1] >>= 3;
	padlen = (index < 56) ? (56 - index) : (120 - index);
	ctx->update(ctx, padding, padlen);
	ctx->update(ctx, bits, 8);
}

void	md5final(ctx_t *ctx)
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
	ctx->encode(bits, ctx->b, 8);
	ctx->b[0] >>= 3;
	padlen = (index < 56) ? (56 - index) : (120 - index);
	ctx->update(ctx, padding, padlen);
	ctx->update(ctx, bits, 8);
}
