#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1000

enum {
	A,
	C,
	G,
	T,
	END
};

int
main()
{
	char buffer[BUFSIZE];
	unsigned counts[END];
	char *c;

	memset(counts, 0, sizeof(counts));

	while (read(STDIN_FILENO, buffer, BUFSIZE) > 0) {
		c = buffer;
		while (*c && *c != '\n') {
			switch (*c) {
			case 'A':
				counts[A]++;
				break;
			case 'C':
				counts[C]++;
				break;
			case 'G':
				counts[G]++;
				break;
			case 'T':
				counts[T]++;
				break;
			default:
				fprintf(stderr, "invalid char %c\n", *c);
				return 1;
			}
			c++;
		}
	}
	printf("%d %d %d %d\n", counts[A], counts[C], counts[G], counts[T]);
	return 0;
}
