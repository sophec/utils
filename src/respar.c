/*
 * respar.c - Compute effective resistance of parallel resistors
 * Author: Sophie Eccles
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double val;
	double sum = 0.0;
	int i;
	char *end;

	if (argc < 2) {
		fprintf(stderr, "usage: %s R1 [R2...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; ++i) {
		val = strtod(argv[i], &end);

		if (errno == ERANGE) {
			fprintf(stderr, "argument out of range: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		if (end == argv[i]) {
			fprintf(stderr, "invalid argument: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		sum += 1.0 / val;
	}

	printf("equivalent resistance: %g Ohms\n", 1.0 / sum);

	exit(EXIT_SUCCESS);
}
