// a return of 0 means a stop codon
char codon_to_amino(const char *codon);
// allocates a string, must be freed by caller
char *rna_to_protein(char *rna);
