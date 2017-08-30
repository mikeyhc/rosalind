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

	assert(fgets(buffer, BUFSIZE, stdin));
	trim_r(buffer);
	printf("%s\n", rna_to_protein(buffer));
	return 0;
}
