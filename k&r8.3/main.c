#include<stdio.h>
#include<error.h>
#include<errno.h>

#include "def.h"

_FILE _iob[OPEN_MAX];

int main(int argc, char **argv) {

	if(argc > 3)
		error(1, errno, "Syntax:\n./run filename1 [filename2]\n");

	_FILE *fp;

	if(argc >= 2)
		if(!(fp = _fopen(argv[1], "r")))
			error(1, errno, "no such file...\n");
	return 0;
}
