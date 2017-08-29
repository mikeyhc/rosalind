#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "fasta.h"

int
read_fasta(Fasta *fasta)
{
	Fasta *fp;
	char *offset, buffer[DNA_LEN];
	size_t len;
	int count;

	fp = fasta;
	offset = fp->dna;
	count = 1;

	assert(fgets(buffer, DNA_LEN, stdin));
	strncpy(fp->name, buffer + 1, strlen(buffer) - 2);

	while (fgets(buffer, DNA_LEN, stdin)) {
		len = strlen(buffer);

		/* read name */
		if (buffer[0] == '>') {
			offset = '\0';
			fp++;
			count++;
			strncpy(fp->name, buffer + 1, len - 2);
			offset = fp->dna;
		/* read dna string */
		} else {
			strncpy(offset, buffer, len - 1);
			offset += len - 1;
		}
	}
	offset = '\0';

	return count;
}
