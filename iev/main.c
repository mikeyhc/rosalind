#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/util.h"

#define BUFFER_SIZE 64

int
main(int argc, char **argv)
{
	float dd, dh, dr, hh, hr;
	char buf[BUFFER_SIZE];
	size_t len;

	if (argc < 7) {
		fprintf(stderr, "usage: %s DD DH DR HH HR RR\n", argv[0]);
		exit(1);
	}

	dd = read_number(argv[1]);
	dh = read_number(argv[2]);
	dr = read_number(argv[3]);
	hh = read_number(argv[4]);
	hr = read_number(argv[5]);
	/* eat RR value as it is part of the question but not the answer */
	read_number(argv[6]);

	/* to trim trailing 0's */
	sprintf(buf, "%f", (dd + dh + dr + (hh * 0.75) + (hr * 0.5)) * 2);
	for (len = strlen(buf) - 1; buf[len] == '0' || buf[len] == '.'; len--);
	buf[len + 1] = '\0';
	printf("%s\n", buf);

	return 0;
}
