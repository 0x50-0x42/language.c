#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<string.h>

#include "def.h"

_FILE _iob[OPEN_MAX];

int main(int argc, char **argv) {

	if(argc > 3)
		error(1, errno, "Syntax:\n./run filename1 [filename2]\n");

	_FILE *fp1, *fp2;

	if(argc == 1) {
		fp1 = _stdin;
		fp2 = _stdout;
	}

	else if(argc >= 2) {
		// file to be read from
		if(strcmp(argv[1], "stdin") != 0) {
			if(!(fp1 = _fopen(argv[1], "r")))
				error(1, errno, "Failed to open file...\n");
		}

		else
			fp1 = _stdin; // by default, read input from the standard input

		// file to be written into
		if(argc == 3) {
			if(!(fp2 = _fopen(argv[2], "w")))
				error(1, errno, "Failed to open file...\n");
		}

		else
			fp2 = _stdout; // by default, write to standard output
	}

	int c;

	while((c = filbuf(fp1)) != _EOF && c != _ERR)
		_flushbuf(c, fp2); // flush characters one-by-one into fp2

	_fflush(fp2);


	_fclose(fp1);
	_fclose(fp2);

	return 0;
}
