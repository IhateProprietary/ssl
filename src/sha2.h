#ifndef SHA2_H
# define SHA2_H

# include <stdint.h>
# include "sha2type.h"

uint32_t	rotl(uint32_t x, uint32_t n);
uint32_t	rotr(uint32_t x, uint32_t n);
uint32_t	sha2sig1(uint32_t x);
uint32_t	sha2sig0(uint32_t x);
uint32_t	sha2ep0(uint32_t x);
uint32_t	sha2ep1(uint32_t x);
uint32_t	sha2ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t	sha2maj(uint32_t x, uint32_t y, uint32_t z);
void		sha2encode(uint8_t *dst, uint32_t *src, uint32_t len);
void		sha2decode(uint32_t *dst, uint8_t *src, uint32_t len);
void		sha2init(sha2ctx_t *ctx, uint32_t *init);
void		sha2update(sha2ctx_t *ctx, uint8_t *input, uint32_t size);
void		sha2transform(uint32_t *r, uint8_t *b);
void		sha2final(uint8_t *digest, sha2ctx_t *ctx, uint32_t digsize);

#endif
