#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/util.h"

#define BUFSIZE 1001

int
main()
{
	char dna[BUFSIZE], sub[BUFSIZE];
	size_t i, len;

	assert(fgets(dna, BUFSIZE, stdin));
	trim_r(dna);
	assert(fgets(sub, BUFSIZE, stdin));
	trim_r(sub);

	len = strlen(sub);

	for (i = 0; *(dna + i + len - 1) != '\0'; i++) {
		if (!strncmp(dna + i, sub, len))
			printf("%ld ", i + 1);
	}
	printf("\n");

	return 0;
}
