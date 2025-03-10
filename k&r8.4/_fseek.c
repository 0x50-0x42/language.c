#include<stdio.h>
#include<unistd.h>

#include "def.h"

int _fseek(_FILE *fp, long offset, int whence) {

	// check the flag of the file pointer
	if((fp->flag & (_READ | _WRITE)) == _READ) {
	}

	else if((fp->flag & (_READ | _WRITE)) == _WRITE) {
	}

	else
		return 1; // unknown flag
}
