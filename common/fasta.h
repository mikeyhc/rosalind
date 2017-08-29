#define NAME_LEN 16
#define DNA_LEN 1001

typedef struct {
	char name[NAME_LEN];
	char dna[DNA_LEN];
} Fasta;

int read_fasta(Fasta *fasta);
