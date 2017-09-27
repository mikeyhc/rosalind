#define NAME_LEN 32
#define DNA_LEN 10001

typedef struct {
	char name[NAME_LEN];
	char dna[DNA_LEN];
} Fasta;

int read_fasta(Fasta *fasta);
