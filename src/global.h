/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:09:02 by jye               #+#    #+#             */
/*   Updated: 2019/03/15 20:28:19 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdint.h>
# include <stdlib.h>

# define TYPEDEF(name) typedef struct s_##name name##_t
# define CTX TYPEDEF(ctx)
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

enum	e_error {
	CMD_ERROR = 1,
	OPT_ERROR = 2,
	FILE_ERROR = 3
};

enum	e_opt {
	SUMARGV = 0x1,
	STDOUT = 0x2,
	QUIET = 0x4,
	REVERSE = 0x8,
	DID_HIS_JOB = 0x10
};

CTX;

struct	s_ctx
{
	uint32_t	b[2];
	uint8_t		buf[64];
	uint32_t	r[8];
	int			opt;
	uint32_t	hashsize;
	int			ac;
	char		**av;
	void		(*update)(ctx_t *, uint8_t *, uint64_t);
	void		(*decode)(uint32_t *, uint8_t *, uint32_t);
	void		(*encode)(uint8_t *, uint32_t *, uint32_t);
	void		(*final)(ctx_t *);
	char		*hashname;
	char		*context;
	char		*s_;
	size_t		len;
};

ctx_t	*hash_init(int ac, char **av, ctx_t *ctx);
void	hash_result(ctx_t *ctx);
void	hash_final(ctx_t *ctx);
void	hash_update(ctx_t *ctx, uint8_t *data, uint64_t len);
void	error(char *ctx, int type);
void	internal_home_made_exit(int ret);
void	fhash_digest(ctx_t *ctx, int fd, ctx_t *reset);
void	shash_digest(ctx_t *ctx, char *s, ctx_t *reset);
void	hash_stdin(ctx_t *ctx, int opt, ctx_t *reset);

#endif
