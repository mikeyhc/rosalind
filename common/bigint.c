/* bigint.c
 * A very, very crappy bigint library so I can get through the
 * rosalind challenges, should be used for nothing else ever
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigint.h"

#define CELL_MAX 10000000000 /* largest 32 bit power of 10 */

void
bigint_init(uint64_t in, uint64_t *out)
{
	int i;

	for (i = 0; i < MAX_CELLS; i++) {
		out[i] = in % CELL_MAX;
		in /= CELL_MAX;
	}
	/* impossible */
	assert(!in);
}

void
bigint_bigint_copy(uint64_t *dest, const uint64_t *src)
{
	/* assumes 8 bit bytes */
	memcpy(dest, src, sizeof(uint64_t) * MAX_CELLS);
}

int
bigint_bigint_equal(const uint64_t *a, const uint64_t *b)
{
	int i;

	for (i = MAX_CELLS - 1; i >= 0; i--) {
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

void
bigint_bigint_add(const uint64_t *a, const uint64_t *b, uint64_t *out)
{
	size_t i;
	uint64_t t, carry;

	carry = 0;
	for (i = 0; i < MAX_CELLS; i++) {
		t = a[i] + b[i] + carry;
		out[i] = t % CELL_MAX;
		carry = t / CELL_MAX;
	}

	/* overflow */
	assert(!carry);
}

void
bigint_bigint_sub(const uint64_t *a, const uint64_t *b, uint64_t *out)
{
	size_t i;
	uint64_t carry;

	carry = 0;
	for (i = 0; i < MAX_CELLS; i++) {
		if (a[i] < b[i]) {
			out[i] = (a[i] + CELL_MAX) - b[i] - carry;
			carry = 1;
		} else {
			out[i] = a[i] - b[i] - carry;
			carry = 0;
		}
	}

	/* underflow */
	assert(!carry);
}

void
bigint_print(const uint64_t *in)
{
	size_t i;
	for (i = MAX_CELLS; i; i--) {
		if(in[i-1] > 0) {
			printf("%lu", in[i-1]);
			break;
		}
	}
	/* number is 0 */
	if (i == 0 && in[0] == 0) {
		printf("0\n");
		return;
	}
	for (i = i-1; i; i--)
		printf("%.10lu", in[i-1]);
	putchar('\n');
}
