/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:12:00 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:12:04 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "sha2.h"

void	sha2final(uint8_t *digest, ctx_t *ctx, uint32_t digsize)
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
	sha2encode(bits, ctx->b, 8);
	ctx->b[1] >>= 3;
	padlen = (index < 56) ? (56 - index) : (120 - index);
	sha2update(ctx, padding, padlen);
	sha2update(ctx, bits, 8);
	sha2encode(digest, ctx->r, digsize);
}
