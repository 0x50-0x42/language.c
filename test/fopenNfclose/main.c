// A beautiful implementation shown in K&R2


#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<unistd.h>

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

	if(!(fp = _fopen(argv[1], "r")))
		error(1, errno, "failed to open file!");

	int c;

	while((c = filbuf(fp)) != _EOF)
		printf("%c", c);

	// close the file
	close(fp->fd);

	return 0;
}
