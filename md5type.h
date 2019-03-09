#ifndef MD5TYPE_H
# define MD5TYPE_H

# include <stdint.h>

typedef struct s_md5ctx
{
	uint32_t b[2];
	uint8_t buf[64];
	uint32_t r[4];
}	md5ctx_t;

typedef struct s_md5rot
{
	const uint32_t *rot;
	const uint32_t *sin;
	uint32_t *x;
}	md5rot_t;

#endif
