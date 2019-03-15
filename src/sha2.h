/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:08:53 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 18:37:37 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2_H
# define SHA2_H

# include <stdint.h>
# include "global.h"

uint32_t	rotl(uint32_t x, uint32_t n);
uint32_t	rotr(uint32_t x, uint32_t n);
uint32_t	sha2sig1(uint32_t x);
uint32_t	sha2sig0(uint32_t x);
uint32_t	sha2ep0(uint32_t x);
uint32_t	sha2ep1(uint32_t x);
uint32_t	sha2ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t	sha2maj(uint32_t x, uint32_t y, uint32_t z);
void		sha2encode(uint8_t *dst, uint32_t *src, uint32_t len);
void		sha2decode(uint32_t *dst, uint8_t *src, uint32_t len);
void		sha2transform(uint32_t *r, uint8_t *b);
void		sha2update(ctx_t *r, uint8_t *b, uint64_t size);
void		sha2final(ctx_t *r);

#endif
