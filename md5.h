#ifndef MD5_h
# define MD5_H

# include <stdint.h>
# include "md5type.h"
# include "md5rot.h"

void		md5init(md5ctx_t *ctx);
uint32_t	f(uint32_t x, uint32_t y, uint32_t z);
uint32_t	g(uint32_t x, uint32_t y, uint32_t z);
uint32_t	h(uint32_t x, uint32_t y, uint32_t z);

#endif
