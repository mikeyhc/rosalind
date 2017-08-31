#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/rna.h"
#include "../common/util.h"

#define BUFSIZE 10001

int
main()
{
	char buffer[BUFSIZE];
	char *prot;

	assert(fgets(buffer, BUFSIZE, stdin));
	trim_r(buffer);
	prot = rna_to_protein(buffer);
	if (!prot)
		return 1;
	printf("%s\n", prot);
	return 0;
}
