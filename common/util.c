#include <ctype.h>

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
