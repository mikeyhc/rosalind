#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1000

int
main()
{
	char buffer[BUFSIZE];
	char *c;

	while (read(STDIN_FILENO, buffer, BUFSIZE) > 0) {
		c = buffer;
		while (*c && *c != '\n') {
			switch (*c) {
			case 'A':
				putchar('A');
				break;
			case 'C':
				putchar('C');
				break;
			case 'G':
				putchar('G');
				break;
			case 'T':
				putchar('U');
				break;
			default:
				fprintf(stderr, "invalid char %c\n", *c);
				return 1;
			}
			c++;
		}
	}
	putchar('\n');
	return 0;
}
