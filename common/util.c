#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void
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

long
read_number(const char *src)
{
	long n;
	char *end;
	n = strtol(src, &end, 10);
	if (src == end) {
		fprintf(stderr, "%s is not a valid number\n", src);
		exit(1);
	}
	return n;
}
