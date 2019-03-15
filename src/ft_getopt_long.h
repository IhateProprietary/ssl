/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:56:09 by root              #+#    #+#             */
/*   Updated: 2017/09/24 02:26:04 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_LONG_H
# define FT_GETOPT_LONG_H

enum	e_arg
{
	no_arg,
	req_arg,
	opt_arg
};

struct	s_options
{
	char	*s;
	int		has_arg;
	int		*f;
	int		val;
};

extern int	g_optind_;
extern char	*g_optarg_;
extern int	g_opterr_;

int		ft_getopt_long(int ac, char **av,
						char *optstring, struct s_options *longopt);
int		ft_getopt_long_long(struct s_options *lopt, char **av, char *pname);
void	ft_getopt_init(char **pname, char **nextchar, char *s);

#endif
