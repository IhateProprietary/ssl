/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:09:02 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:13:43 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

struct	s_ctx
{
	uint32_t	b[2];
	uint8_t		buf[64];
	uint32_t	r[8];
};

#endif