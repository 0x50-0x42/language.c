#include<stdio.h>
#include<error.h>
#include<errno.h>

#include "def.h"

_FILE iob[OPEN_MAX] = { /* stdin, stdout and stderr */

	{0, (char*) 0, (char*) 0, _READ, 0},
	{0, (char*) 0, (char*) 0, _WRITE, 1},
	{0, (char*) 0, (char*) 0, _WRITE | _UNBUF, 2} // stderr is to be written unbuffered
}; // the rest of the elements are set to 0s

int main(int argc, char **argv) {
	if(argc == 1)
		error(1, errno, "Please provide a file name...");

	_FILE *fp;

	if(!(fp = _fopen(argv[1], "w")))
		error(1, errno, "failed to open file!");

	return 0;
}
