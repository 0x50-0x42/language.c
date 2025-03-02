#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

// this function only reads characters read, it doesn't write into any file
int filbuf(_FILE *fp) {

	int bufsize;

	if(!fp->_READ) {
		fp->_EOF = 1;
		return '\0';
	}

	// bufsize is 1 if filbuf() is reading unbuffered
	bufsize = (fp->_READ && fp->_UNBUF) ? 1 : _BUFSIZ;

	// if buffer is unallocated
	if(fp->base == NULL) {
		if(!(fp->base = calloc(bufsize, sizeof(char)))) {
			fp->_EOF = 1;
			return '\0';
		}

		fp->ptr = fp->base;
		fp->cnt = read(fp->fd, fp->base, bufsize);
	}

	else {
		// for unbuffered reading
		if(bufsize == 1) {
			fp->ptr = fp->base; // ptr needs to be repeatedly set to base
			fp->cnt = read(fp->fd, fp->base, bufsize);
		}
	}

	// no input was given
	if(--fp->cnt < 0) {
		if(fp->cnt == -1) {
			fp->_EOF = 1;
			return '\0';
		}

		else {
			fp->_ERR = 1;
			return '\0';
		}
	}

	return (unsigned char) *fp->ptr++;
}
