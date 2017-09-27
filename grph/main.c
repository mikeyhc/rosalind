#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/fasta.h"

#define MAX_STRINGS 1001

int
main()
{
	Fasta *data;
	int i, j, count;
	char *suffix;
	size_t len;

	/* too big for stack */
	data = malloc(sizeof(Fasta) * MAX_STRINGS);

	count = read_fasta(data);

	for (i = 0; i < count; i++) {
		len = strlen(data[i].dna);
		suffix = data[i].dna + len - 3;
		for (j = 0; j  < count; j++) {
			if (i == j)
				continue;
			if (!strncmp(suffix, data[j].dna, 3))
				printf("%s %s\n", data[i].name, data[j].name);
		}
	}

	return 0;
}
