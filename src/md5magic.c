/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:56:03 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 15:59:47 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "md5.h"

void					magic(t_md5basic t,
	uint32_t **r,
	uint32_t *x
)
{
	*r[0] += t(*r[1], *r[2], *r[3]) + x[0] + x[2];
	*r[0] = rotl(*r[0], x[1]);
	*r[0] += *r[1];
}
