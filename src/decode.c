/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:53:16 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 15:54:17 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	md5decode(uint32_t *dst, uint8_t *src, uint32_t len)
{
	uint32_t i;
	uint32_t j;
	uint32_t val;

	j = 0;
	i = 0;
	while (j < len)
	{
		val =
			(src[j + 0]) |
			(src[j + 1] << 8) |
			(src[j + 2] << 16) |
			(src[j + 3] << 24);
		dst[i] = val;
		i++;
		j += 4;
	}
}

void	sha2decode(uint32_t *dst, uint8_t *src, uint32_t len)
{
	uint32_t i;
	uint32_t j;
	uint32_t val;

	j = 0;
	i = 0;
	while (j < len)
	{
		val =
			(src[j + 3]) |
			(src[j + 2] << 8) |
			(src[j + 1] << 16) |
			(src[j + 0] << 24);
		dst[i] = val;
		i++;
		j += 4;
	}
}
