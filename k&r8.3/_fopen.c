#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#include "def.h"

const int PERMS = 0666;

_FILE* _fopen(char *filename, char *mode) {
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL; // invalid mode

	_FILE *fp;

	for(fp = _iob; fp - _iob < OPEN_MAX; fp++)
		if((fp->flag & (_READ | _WRITE)) == 0)
			break; // found our file pointer

	if(fp - _iob >= OPEN_MAX)
		return NULL; // no empty file pointer exists

	if(*mode == 'r') {
		if((fp->fd = open(filename, O_RDONLY, 0)) < 0)
			return NULL;
	}

	else if(*mode == 'w') {
		if((fp->fd = creat(filename, PERMS)) < 0)
			return NULL;
	}

	else { // append mode
		if((fp->fd = open(filename, O_WRONLY, 0)) < 0)
			if((fp->fd = creat(filename, PERMS)) < 0)
				return NULL;
		lseek(fp->fd, 0L, 2);
	}

	fp->flag = *mode == 'r' ? _READ : _WRITE;
	fp->cnt = 0;
	fp->base = fp->ptr = NULL;

	return fp;
}
