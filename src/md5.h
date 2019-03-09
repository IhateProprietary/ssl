#ifndef MD5_H
# define MD5_H

# include <stdint.h>
# include "md5type.h"
# include "md5rot.h"

void			md5init(md5ctx_t *ctx);
uint32_t		f(uint32_t x, uint32_t y, uint32_t z);
uint32_t		g(uint32_t x, uint32_t y, uint32_t z);
uint32_t		h(uint32_t x, uint32_t y, uint32_t z);
uint32_t		i(uint32_t x, uint32_t y, uint32_t z);
void			md5final(uint8_t *digest, md5ctx_t *ctx);
void			md5update(md5ctx_t *ctx, uint8_t *input, uint64_t size);
void			md5encode(uint8_t *dst, uint32_t *src, uint32_t len);
void			md5decode(uint32_t *dst, uint8_t *src, uint32_t len);
void			md5transform(uint32_t *r, uint8_t *block);
uint32_t		rotl(uint32_t x, uint32_t n);
void			md5rounds(
	uint32_t (*t)(uint32_t, uint32_t, uint32_t),
	uint32_t *reg,
	uint32_t *a,
	md5rot_t rot
);
void			magic(
	uint32_t (*t)(uint32_t, uint32_t, uint32_t),
	uint32_t **r,
	uint32_t *x
);
#endif
