#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#include "def.h"

const int PERMS = 0666;

_FILE *_fopen(char *filename, char *mode) {
	
	// check if the mode is valid
	if(*mode != 'w' && *mode != 'r' && *mode != 'a')
		return NULL;

	_FILE *fp;

	// find a file pointer with an emtpy flag
	for(fp = iob; fp < iob + OPEN_MAX; fp++)
		if(!fp->_READ && !fp->_WRITE, !fp->_UNBUF, !fp->_EOF && !fp->_ERR) // found a file pointer
			break;

	// as per the mode, either create and open or just open a file
	if(*mode == 'w') {
		if((fp->fd = creat(filename, PERMS)) < 0)
			return NULL;
		if((fp->fd = open(filename, O_WRONLY, 0)) < 0)
			return NULL;
		fp->_WRITE = 1;
	}

	else if(*mode == 'r') {
		if((fp->fd = open(filename, O_RDONLY, 0)) < 0)
			return NULL;
		fp->_READ = 1;
	}

	else { // append mode
		if((fp->fd = open(filename, O_WRONLY, 0)) < 0) {
			if((fp->fd = creat(filename, PERMS)) < 0)
				return NULL;
			if((fp->fd = open(filename, O_WRONLY, 0)) < 0)
				return NULL;

		}

		fp->_WRITE = 1;
		lseek(fp->fd, 0L, 2);
	}

	fp->base = NULL;
	fp->ptr = fp->base;
	fp->cnt = 0;

	return fp;
}
