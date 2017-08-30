#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "rna.h"

typedef union {
	char end;
	struct rna_lookup_node *nodes;
} RnaNodeType;

typedef struct rna_lookup_node {
	RnaNodeType data;
} RnaLookupNode;

RnaLookupNode *lookup = NULL;

static size_t
rna_index(char c)
{
	switch (c) {
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'U':
		return 3;
	}
	abort();
}

static void
build_node(RnaLookupNode **n)
{
	RnaLookupNode *a, *b;

	*n = malloc(sizeof(RnaLookupNode));
	assert(*n);
	(*n)->data.nodes = malloc(sizeof(RnaLookupNode) * 4);
	assert((*n)->data.nodes);
	for (a = (*n)->data.nodes; a != (*n)->data.nodes + 4; a++) {
		a->data.nodes = malloc(sizeof(RnaLookupNode) * 4);
		assert(a->data.nodes);
		for (b = a->data.nodes; b != a->data.nodes + 4; b++) {
			b->data.nodes = malloc(sizeof(RnaLookupNode) * 4);
			assert(b->data.nodes);
		}
	}

}

static void
table_insert(const char *codon, char amino)
{
	RnaLookupNode *n;

	n = &lookup->data.nodes[rna_index(codon[0])];
	n = &n->data.nodes[rna_index(codon[1])];
	n = &n->data.nodes[rna_index(codon[2])];
	n ->data.end = amino;
}

static void
build_table(void)
{
	if (lookup)
		return;
	build_node(&lookup);
	table_insert("UUU", 'F');
	table_insert("UUC", 'F');
	table_insert("UUA", 'L');
	table_insert("UUG", 'L');
	table_insert("UCU", 'S');
	table_insert("UCC", 'S');
	table_insert("UCA", 'S');
	table_insert("UCG", 'S');
	table_insert("UAU", 'Y');
	table_insert("UAC", 'Y');
	table_insert("UAA", 0);
	table_insert("UAG", 0);
	table_insert("UGU", 'C');
	table_insert("UGC", 'C');
	table_insert("UGA", 0);
	table_insert("UGG", 'W');
	table_insert("CUU", 'L');
	table_insert("CUC", 'L');
	table_insert("CUA", 'L');
	table_insert("CUG", 'L');
	table_insert("CCU", 'P');
	table_insert("CCC", 'P');
	table_insert("CCA", 'P');
	table_insert("CCG", 'P');
	table_insert("CAU", 'H');
	table_insert("CAC", 'H');
	table_insert("CAA", 'Q');
	table_insert("CAG", 'Q');
	table_insert("CGU", 'R');
	table_insert("CGC", 'R');
	table_insert("CGA", 'R');
	table_insert("CGG", 'R');
	table_insert("AUU", 'I');
	table_insert("AUC", 'I');
	table_insert("AUA", 'I');
	table_insert("AUG", 'M');
	table_insert("ACU", 'T');
	table_insert("ACC", 'T');
	table_insert("ACA", 'T');
	table_insert("ACG", 'T');
	table_insert("AAU", 'N');
	table_insert("AAC", 'N');
	table_insert("AAA", 'K');
	table_insert("AAG", 'K');
	table_insert("AGU", 'S');
	table_insert("AGC", 'S');
	table_insert("AGA", 'R');
	table_insert("AGG", 'R');
	table_insert("GUU", 'V');
	table_insert("GUC", 'V');
	table_insert("GUA", 'V');
	table_insert("GUG", 'V');
	table_insert("GCU", 'A');
	table_insert("GCC", 'A');
	table_insert("GCA", 'A');
	table_insert("GCG", 'A');
	table_insert("GAU", 'D');
	table_insert("GAC", 'D');
	table_insert("GAA", 'E');
	table_insert("GAG", 'E');
	table_insert("GGU", 'G');
	table_insert("GGC", 'G');
	table_insert("GGA", 'G');
	table_insert("GGG", 'G');
}

char
codon_to_amino(const char *codon)
{
	RnaLookupNode *first, *second, *third;

	build_table();
	first = &lookup->data.nodes[rna_index(codon[0])];
	second = &first->data.nodes[rna_index(codon[1])];
	third = &second->data.nodes[rna_index(codon[2])];
	return third->data.end;
}

char*
rna_to_protein(char *rna)
{
	char *s, *ret;

	ret = malloc(strlen(rna) / 3 + 1);
	assert(ret);
	for (s = ret; *rna != '\0'; rna += 3, s++) {
		*s = codon_to_amino(rna);
		if (!*s)
			break;
	}
	*s = '\0';

	return ret;
}
