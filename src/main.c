/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:04:50 by jye               #+#    #+#             */
/*   Updated: 2019/03/22 18:16:07 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "global.h"
#include "ft_printf.h"
#include "ft_getopt_long.h"

void		usage(void)
{
	ft_dprintf(2, "usage: ft_ssl command [command opts] [command args]\n"
		"Message Digest commands:\nmd5\nsha224\nsha256\n");
	internal_home_made_exit(2);
}

void		error(char *context, int type)
{
	if (type == CMD_ERROR)
		ft_dprintf(2, "ft_ssl: Error:'%s' is an invalid command.\n"
			"Message Digest commands:\nmd5\nsha224\nsha256\n", context);
	if (type == OPT_ERROR)
		usage();
	internal_home_made_exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	ctx_t	ctx;
	ctx_t	*algo;
	int		i;
	int		fd;

	if (ac < 2)
		usage();
	algo = hash_init(ac - 1, av + 1, &ctx);
	i = g_optind_ + 1;
	if (!(ctx.opt & DID_HIS_JOB) && i == ac)
		hash_stdin(&ctx, QUIET, algo);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			ft_dprintf(2, "ft_ssl: File '%s' is not valid.\n", av[i]);
		else
		{
			ctx.context = av[i];
			fhash_digest(&ctx, fd, algo);
			close(fd);
		}
		i++;
	}
}
