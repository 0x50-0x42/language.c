#include<stdio.h>

#include "def.h"

_FILE _iob[OPEN_MAX] = {
	{0, NULL, NULL, _READ, 0},
	{0, NULL, NULL, _WRITE, 1},
	{0, NULL, NULL, (_WRITE | _UNBUF), 2}
};

int main(int argc, char **argv) {

	if(argc == 1)
		error(1, errno, "Please pass in atmost two files...\n");
	else if(argc > 3)
		error(1, errno, "Too many parameters...\n");

	_FILE *fp1, *fp2;


	if(!(fp1 = _fopen(argv[1], "r")))
		error(1, errno, "Failed to open file for reading...\n");
	if(argc == 2)
		fp2 = _stdout;
	else
		if(!(fp2 = _fopen(argv[2], "w")))
			error(1, errno, "Failed to open file writing...\n");

	return 0;
}
