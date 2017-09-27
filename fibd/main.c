#include <stdio.h>
#include <stdlib.h>
#include "../common/bigint.h"
#include "../common/util.h"

#define MAX_N 100

int
main(int argc, char **argv)
{
	long month, n, m;
	// uint64_t *adults, *babies, *born[MAX_N], *old_adults, *zero;
	BIGINT(adults);
	BIGINT(babies);
	BIGINT(born[MAX_N]);
	BIGINT(old_adults);
	BIGINT(die);
	BIGINT(temp);
	BIGINT(final);

	if (argc < 3) {
		fprintf(stderr, "not enough arguments\n");
		exit(1);
	}

	n = read_number(argv[1]);
	m = read_number(argv[2]);

	bigint_init(0, adults);
	bigint_init(1, babies);
	for (month = 1; month < n; month++) {
		if (month - m > 0)
			bigint_bigint_copy(die, born[month - m]);
		else
			bigint_init(0, die);
		/* calculate current adults */
		bigint_bigint_sub(adults, die, temp);
		bigint_bigint_copy(adults, temp);
		/* store data for this run */
		bigint_bigint_copy(old_adults, adults);
		bigint_bigint_copy(born[month], babies);
		/* calculating this generation */
		bigint_bigint_add(adults, babies, temp);
		bigint_bigint_copy(adults, temp);
		bigint_bigint_copy(babies, old_adults);
	}
	bigint_bigint_add(adults, babies, temp);
	bigint_bigint_sub(temp, born[month - m], final);
	bigint_print(final);

	return 0;
}
