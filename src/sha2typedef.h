/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2typedef.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:09:07 by jye               #+#    #+#             */
/*   Updated: 2019/03/11 16:21:11 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA2TYPEDEF_H
# define SHA2TYPEDEF_H

# define TYPEDEF(name) typedef struct s_##name name##_t
# define CTX TYPEDEF(ctx)

CTX;

#endif
