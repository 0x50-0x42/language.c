#include<stdio.h>
#include<error.h>
#include<errno.h>

#include "def.h"

_FILE _iob[OPEN_MAX] = {
	{0, NULL, NULL, _READ, 0},  // stdin
	{0, NULL, NULL, _WRITE, 1}, // stdout
	{0, NULL, NULL, (_WRITE | _UNBUF), 2} // stderr
};

int main(int argc, char **argv) {

	// no arguments passed
	if(argc == 1)
		error(1, errno, "Please pass in atmost two files...\n");
	// more than 3 arguments passed
	else if(argc > 3)
		error(1, errno, "Too many parameters...\n");

	_FILE *fp1, *fp2;


	if(!(fp1 = _fopen(argv[1], "r")))
		error(1, errno, "Failed to open file for reading...\n");
	// if only one filename is passed
	if(argc == 2)
		fp2 = _stdout; // the third file will be stdout

	else // otherwise, the file will be opened for writing
		if(!(fp2 = _fopen(argv[2], "w")))
			error(1, errno, "Failed to open file for writing...\n");

	int c;

	while((c = filbuf(fp1)) != _EOF && c != _ERR)
		_flushbuf(c, fp2);

	_fflush(fp2);

	_fclose(fp1);
	_fclose(fp2);

	return 0;
}
