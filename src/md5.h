/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:55:30 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 18:37:08 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <stdint.h>
# include "md5typedef.h"
# include "global.h"
# include "md5typedef.h"
# include "md5type.h"
# include "md5rot.h"

uint32_t		f(uint32_t x, uint32_t y, uint32_t z);
uint32_t		g(uint32_t x, uint32_t y, uint32_t z);
uint32_t		h(uint32_t x, uint32_t y, uint32_t z);
uint32_t		i(uint32_t x, uint32_t y, uint32_t z);
void			md5encode(uint8_t *dst, uint32_t *src, uint32_t len);
void			md5decode(uint32_t *dst, uint8_t *src, uint32_t len);
void			md5transform(uint32_t *r, uint8_t *block);
void			md5update(ctx_t *r, uint8_t *b, uint64_t size);
void			md5final(ctx_t *r);
uint32_t		rotl(uint32_t x, uint32_t n);
void			md5rounds(
	uint32_t (*t)(uint32_t, uint32_t, uint32_t),
	uint32_t *reg,
	uint32_t *a,
	md5rot_t rot
);
void			md5magic(
	uint32_t (*t)(uint32_t, uint32_t, uint32_t),
	uint32_t **r,
	uint32_t *x
);
#endif
