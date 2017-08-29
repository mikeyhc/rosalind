#include <stdio.h>
#include "../common/fasta.h"

static float
gc_content(char *dna)
{
	float total_count, gc_count;

	gc_count = 0;
	total_count = 0;
	while (*dna != '\0') {
		if (*dna == 'G' || *dna == 'C')
			gc_count++;
		total_count++;
		dna++;
	}

	return gc_count / total_count * 100;
}

int
main()
{
	Fasta data[10];
	int count;
	char *max_name;
	float gc, max_content;

	count = read_fasta(data);
	max_name = data[0].name;
	max_content = gc_content(data[0].dna);
	for (int i = 1; i < count; i++) {
		gc = gc_content(data[i].dna);
		if (gc > max_content) {
			max_content = gc;
			max_name = data[i].name;
		}
	}

	printf("%s\n%.6f\n", max_name, max_content);
	return 0;
}
