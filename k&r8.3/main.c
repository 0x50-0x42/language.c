#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<string.h>

#include "def.h"

_FILE _iob[OPEN_MAX] = {
	{0, NULL, NULL, _READ, 0},
	{0, NULL, NULL, _WRITE, 1},
	{0, NULL, NULL, (_WRITE | _UNBUF), 2}
};

int main(int argc, char **argv) {

	// not more than three arguments
	if(argc > 3)
		error(1, errno, "Syntax:\n./run filename1 [filename2]\n");

	_FILE *fp1, *fp2;


	// each file pointer has a buffer that it uses to write contents into its respective file
	// fp1 is the input file buffer (the file from which it will take input) and
	// fp2 is the output file buffer (the file to which it will write output to)
	// both of these have a buffer (temporary) that each uses --
	// fp1 uses it to store the input data read from the file
	// fp2 uses it to store the output temporarily before flushing it all
	// into the respective file

	// if no arguments were provided
	if(argc == 1) {
		fp1 = _stdin;
		fp2 = _stdout;
	}

	else if(argc >= 2) {
		if(argc == 2) { // only the file to read from was provided
			if(!(fp1 = _fopen(argv[1], "r")))
				error(1, errno, "Failed to open file...\n");
			fp2 = _stdout; // by default, the file to write to will be stdout
		}

		else {
			if(!(fp1 = _fopen(argv[1], "r")))
				error(1, errno, "Failed to open file....\n");
			if(!(fp2 = _fopen(argv[2], "w")))
				error(1, errno, "Failed to open file....\n");
		}
	}

	int c;

	while((c = filbuf(fp1)) != _EOF && c != _ERR)
		_flushbuf(c, fp2); // flush characters one-by-one into fp2

	_fflush(fp2);


	_fclose(fp1);
	_fclose(fp2);

	return 0;
}
