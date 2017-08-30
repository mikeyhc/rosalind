#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static float
read_float(const char *sn)
{
	char *end;
	float n;

	n = (float)strtol(sn, &end, 10);
	if (sn == end) {
		fprintf(stderr, "%s is not a valid number\n", sn);
		exit(1);
	}
	return n;
}

int
main(int argc, char **argv)
{
	float homo_dom, hetro, homo_rec, total;
	float homo_dom_p, _hetro_p, hetro_p, _homo_rec_p, homo_rec_p;

	if (argc != 4) {
		fprintf(stderr, "invalid number of arguments provided\n");
		return 1;
	}

	homo_dom = read_float(argv[1]);
	hetro = read_float(argv[2]);
	homo_rec = read_float(argv[3]);
	total = homo_dom + hetro + homo_rec;

	homo_dom_p = homo_dom / total;
	_hetro_p = hetro / 2 / total;
	hetro_p = _hetro_p
		+ (_hetro_p * (homo_dom / (total - 1)))
		+ (_hetro_p * ((hetro - 1) / 2 / (total - 1)));
	_homo_rec_p = homo_rec / total;
	homo_rec_p = (_homo_rec_p * (homo_dom / (total - 1)))
		   + (_homo_rec_p * (hetro / 2 / (total - 1)));
	printf("%.6f\n", homo_dom_p + hetro_p + homo_rec_p);

	return 0;
}
