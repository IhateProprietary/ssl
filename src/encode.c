/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:54:26 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:22:43 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	md5encode(uint8_t *dst, uint32_t *src, uint32_t len)
{
	uint32_t i;
	uint32_t j;

	i = 0;
	j = 0;
	while (j < len)
	{
		dst[j] = (src[i]) & 0xff;
		dst[j + 1] = (src[i] >> 8) & 0xff;
		dst[j + 2] = (src[i] >> 16) & 0xff;
		dst[j + 3] = (src[i] >> 24) & 0xff;
		i++;
		j += 4;
	}
}

void	sha2encode(uint8_t *dst, uint32_t *src, uint32_t len)
{
	uint32_t i;
	uint32_t j;

	i = 0;
	j = 0;
	while (j < len)
	{
		dst[j] = (src[i] >> 24) & 0xff;
		dst[j + 1] = (src[i] >> 16) & 0xff;
		dst[j + 2] = (src[i] >> 8) & 0xff;
		dst[j + 3] = (src[i] >> 0) & 0xff;
		i++;
		j += 4;
	}
}
