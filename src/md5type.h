/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:05:06 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:15:36 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5TYPE_H
# define MD5TYPE_H

# include <stdint.h>

typedef uint32_t(*t_md5basic)(uint32_t, uint32_t, uint32_t);

struct	s_md5rot
{
	const uint32_t	*rot;
	const uint32_t	*sin;
	uint32_t		*x;
};

#endif
