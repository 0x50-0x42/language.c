// file-based approach
// got the idea from clc-wiki

#include<time.h>
#include<stdio.h>
#include<error.h>
#include<errno.h>

#include "def.h"

_FILE iob[OPEN_MAX] = { // stdin, stdout and stderr
	{0, NULL, NULL, 0, 1, 0, 0, 0, 0},
	{0, NULL, NULL, 1, 0, 1, 0, 0, 0},
	{0, NULL, NULL, 2, 0, 1, 1, 0, 0}
};

int main(int argc, char **argv) {

	double start = (double)clock();
	start /= CLOCKS_PER_SEC;

	struct tm execTm;

	if(argc == 1)
		error(1, errno, "filename must be passed as args....");
	if(argc > 2)
		error(1, errno, "only one file name required....");

	_FILE* fp;

	if(!(fp = _fopen(argv[1], "r")))
		error(1, errno, "failed to open file...");


	int c;
	while(!fp->_EOF && !fp->_ERR)
		printf("%c", filbuf(fp));

	_fclose(fp);

	printf("\nTime taken: %lf\n", (((double)clock()) / CLOCKS_PER_SEC) - start);

	return 0;
}
