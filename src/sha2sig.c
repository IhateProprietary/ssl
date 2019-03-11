/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:13:05 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:13:08 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "sha2.h"

uint32_t	sha2sig0(uint32_t x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ ((x) >> 3));
}

uint32_t	sha2sig1(uint32_t x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ ((x) >> 10));
}

uint32_t	sha2ep0(uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

uint32_t	sha2ep1(uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}
