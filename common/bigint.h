/* TODO: remove this prick, no headers in headers sucka */
#include <stdint.h>

#define MAX_CELLS 4	     /* support up to 128 bit numbers (not really) */
#define BIGINT(x) uint64_t x[MAX_CELLS]

void bigint_init(uint64_t in, uint64_t *out);
void bigint_bigint_copy(uint64_t *dest, const uint64_t *src);
int bigint_bigint_equal(const uint64_t *a, const uint64_t *b);
void bigint_bigint_add(const uint64_t *a, const uint64_t *b, uint64_t *out);
void bigint_bigint_sub(const uint64_t *a, const uint64_t *b, uint64_t *out);
void bigint_print(const uint64_t *in);
