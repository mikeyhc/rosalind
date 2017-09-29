#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/fasta.h"

#define MAX_STRINGS 101

static int substr_eq(const char *src, const char *dest, int size);

static int
substr_eq(const char *src, const char *dest, int size)
{
	int offset;
	size_t len;

	len = strlen(dest);
	for (offset = 0; offset + size < len; offset++) {
		if (!strncmp(src, dest + offset, size))
			return 1;
	}
	return 0;
}

int
main()
{
	Fasta *data;
	unsigned i, j, k, count;
	char *shortest;
	size_t len, l;

	/* too big for stack */
	data = malloc(sizeof(Fasta) * MAX_STRINGS);
	count = read_fasta(data);

	/* find the shortest string */
	shortest = data[0].dna;
	len = strlen(shortest);
	for (i = 1; i < count; i++) {
		l = strlen(data[i].dna);
		if (l < len) {
			len = l;
			shortest = data[i].dna;
		}
	}

	for (i = len; i > 0; i--) {
		for (j = 0; j + i < len; j++) {
			for (k = 0; k < count; k++) {
				if (!substr_eq(shortest + j, data[k].dna, i))
					break;
			}

			if (k == count) {
				goto DONE;
			}
		}
	}

DONE:
	*(shortest + j + i) = '\0';
	printf("%s\n", shortest + j);

	return 0;
}
