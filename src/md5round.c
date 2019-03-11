/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:16:40 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:17:56 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "md5.h"

void	md5rounds(
	t_md5basic t,
	uint32_t *reg,
	uint32_t *a,
	md5rot_t rot
)
{
	uint32_t		i;
	const uint32_t	*ac;
	const uint32_t	*x;
	const uint32_t	*r;

	i = 0;
	ac = rot.sin;
	x = rot.x;
	r = rot.rot;
	while (i < 16)
	{
		magic(t,
			(uint32_t*[4]){
				&reg[(-i) & 3], &reg[(-i + 1) & 3],
				&reg[(-i + 2) & 3], &reg[(-i + 3) & 3]},
			(uint32_t[3]){x[(a[0] + (i * a[1])) & 0xf],
				r[i & 3], ac[i]});
		i++;
	}
}

void	md5add(uint32_t *r, uint32_t *r_)
{
	r[0] += r_[0];
	r[1] += r_[1];
	r[2] += r_[2];
	r[3] += r_[3];
}

void	md5transform(uint32_t *r, uint8_t *block)
{
	static const uint32_t	rot[16] = {S11, S12, S13, S14, S21, S22, S23, S24,
							S31, S32, S33, S34, S41, S42, S43, S44};
	static const uint32_t	sin[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
		0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
		0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
		0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
		0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
		0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
	uint32_t				r_[4];
	uint32_t				x[16];

	memcpy(r_, r, sizeof(r_));
	decode(x, block, 64);
	md5rounds(f, r_, (uint32_t[2]){0, 1}, (md5rot_t){rot, sin, x});
	md5rounds(g, r_, (uint32_t[2]){1, 5}, (md5rot_t){rot + 4, sin + 16, x});
	md5rounds(h, r_, (uint32_t[2]){5, 3}, (md5rot_t){rot + 8, sin + 32, x});
	md5rounds(i, r_, (uint32_t[2]){0, 7}, (md5rot_t){rot + 12, sin + 48, x});
	md5add(r, r_);
}
