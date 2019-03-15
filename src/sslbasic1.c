/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sslbasic1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:51:21 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 20:29:02 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void		hash_stdin(ctx_t *ctx, int opt, ctx_t *reset)
{
	int		topt;

	topt = ctx->opt;
	ctx->opt = opt;
	fhash_digest(ctx, 0, reset);
	ctx->opt = topt;
	ctx->opt |= DID_HIS_JOB;
}
