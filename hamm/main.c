#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 1001

static void trim_r(char *s);

static void
trim_r(char *s)
{
	char *end;

	end = s;
	while (*end != '\0')
		end++;
	end--;
	while (isspace(*end) || *end == '\n' || *end == '\r')
		end--;
	*(end + 1) = '\0';
}

int
main()
{
	char first[BUFSIZE], second[BUFSIZE];
	char *fp, *sp;
	unsigned errors;

	assert(fgets(first, BUFSIZE, stdin));
	assert(fgets(second, BUFSIZE, stdin));

	fp = first;
	sp = second;
	trim_r(fp);
	trim_r(sp);
	for (errors = 0; *fp != '\0' && *sp != '\0'; fp++, sp++) {
		if (*fp != *sp)
			errors++;
	}

	printf("%d\n", errors);
	return 0;
}
