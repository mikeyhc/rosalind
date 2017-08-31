#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/fasta.h"

#define BUFSIZE 1001
#define MAX_STRINGS 10

static int dna_to_idx(char c);
static char dna_max(const int counts[4]);

static int
dna_to_idx(char c)
{
	switch (c) {
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	}
	return -1;
}

static int
idx_to_dna(char c)
{
	assert(c >= 0 && c <= 3);
	switch (c) {
	case 0:
		return 'A';
	case 1:
		return 'C';
	case 2:
		return 'G';
	}
	return 'T';
}

static char
dna_max(const int counts[4])
{
	int i, max_idx;

	max_idx = 0;
	for (i = 1; i < 4; i++) {
		if (counts[i] > counts[max_idx])
			max_idx = i;
	}

	return idx_to_dna(max_idx);
}

int
main()
{
	Fasta data[MAX_STRINGS];
	int count;
	int i, j, matrix[BUFSIZE][4];
	char consensus[BUFSIZE];

	memset(matrix, 0, BUFSIZE * 4);
	count = read_fasta(data);
	for (i = 0; data[0].dna[i] != '\0'; i++) {
		for (j = 0; j < count; j++) {
			matrix[i][dna_to_idx(data[j].dna[i])]++;
		}
		consensus[i] = dna_max(matrix[i]);
	}
	consensus[i] = '\0';
	printf("%s\n", consensus);
	for (i = 0; i < 4; i++) {
		printf("%c:", idx_to_dna(i));
		for (j = 0; consensus[j] != '\0'; j++)
			printf(" %d", matrix[j][i]);
		printf("\n");
	}

	return 0;
}
