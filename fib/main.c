#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static long
read_number(const char *src)
{
	long n;
	n = strtol(src, NULL, 10);
	if (errno) { fprintf(stderr, "%s is not a valid number\n", src);
		exit(1);
	}
	return n;
}

int
main(int argc, char **argv)
{
	long i, j;
	long n, k, o;

	if (argc < 3) {
		fprintf(stderr, "usage: %s N K\n", argv[0]);
		exit(1);
	}

	n = read_number(argv[1]);
	k = read_number(argv[2]);

	for (i = 1, j = 0; n > 1; o = i, n--, i = i + (j * k), j = o) ;
	printf("%ld\n", i);
	return 0;
}
