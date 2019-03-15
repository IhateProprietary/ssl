/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <jye@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 22:51:33 by jye               #+#    #+#             */
/*   Updated: 2017/09/24 11:28:50 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt_long.h"
#include "ft_printf.h"

static int	ft_getopt_long_long_no_arg(struct s_options *lopt, char *pname)
{
	if (g_optarg_)
	{
		if (g_opterr_)
			ft_dprintf(2, "%s: '--%s' doesn't allow an argument\n",
					pname, lopt->s);
		return ('?');
	}
	if (lopt->f)
		*lopt->f = lopt->val;
	return (lopt->f ? 0 : lopt->val);
}

static int	ft_getopt_long_long_req_arg(struct s_options *lopt, char **av,
										char *pname)
{
	if (!g_optarg_)
		g_optarg_ = av[g_optind_++];
	if (!g_optarg_)
	{
		if (g_opterr_)
			ft_dprintf(2, "%s: '--%s' options requires an argument\n",
					pname, lopt->s);
		return ('?');
	}
	if (lopt->f)
		*lopt->f = lopt->val;
	return (lopt->f ? 0 : lopt->val);
}

static int	ft_getopt_long_long_opt_arg(struct s_options *lopt, char *pname)
{
	(void)pname;
	if (lopt->f)
		*lopt->f = lopt->val;
	return (lopt->f ? 0 : lopt->val);
}

int			ft_getopt_long_long(struct s_options *lopt, char **av, char *pname)
{
	g_optind_ += 1;
	if (lopt == NULL)
		return ('?');
	else if (lopt->has_arg == no_arg)
		return (ft_getopt_long_long_no_arg(lopt, pname));
	else if (lopt->has_arg == req_arg)
		return (ft_getopt_long_long_req_arg(lopt, av, pname));
	else
		return (ft_getopt_long_long_opt_arg(lopt, pname));
}

void		ft_getopt_init(char **pname, char **nextchar, char *s)
{
	g_optind_ = 1;
	*pname = s;
	*nextchar = "";
}
