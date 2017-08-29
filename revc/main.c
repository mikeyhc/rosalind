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
		c = buffer + strlen(buffer) - 1;
		while(*c == '\n' || *c == '\r')
			c--;
		while (*c && *c != '\n') {
			switch (*c) {
			case 'A':
				putchar('T');
				break;
			case 'C':
				putchar('G');
				break;
			case 'G':
				putchar('C');
				break;
			case 'T':
				putchar('A');
				break;
			default:
				fprintf(stderr, "invalid char %c\n", *c);
				return 1;
			}
			c--;
		}
	}
	putchar('\n');
	return 0;
}
