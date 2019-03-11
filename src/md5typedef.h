/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5typedef.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:05:09 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:21:04 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5TYPEDEF_H
# define MD5TYPEDEF_H

# define TYPEDEF(name) typedef struct s_##name name##_t
# define MD5CTX TYPEDEF(ctx)
# define ROT TYPEDEF(md5rot)

MD5ROT;
CTX;

#endif
