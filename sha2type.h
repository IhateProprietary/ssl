#ifndef SHA2TYPE_H
# define SHA2TYPE_H

# include <stdint.h>

typedef struct	s_sha2ctx
{
	uint32_t	b[2];
	uint8_t		buf[64];
	uint32_t	r[8];
}	sha2ctx_t;

#endif
