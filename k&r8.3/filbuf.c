#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include "def.h"


// allocate and fill the buffer
int filbuf(_FILE *fp) {

	// check the flag
	if(fp->flag & (_READ | _EOF | _ERR) != _READ)
		return _EOF;

	int bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZ;

	// checking if the buffer is empty
	if(fp->base == NULL) {
		if(!(fp->base = calloc(bufsize, sizeof(char))))
			return _EOF;
		fp->ptr = base;
		fp->cnt = read(fp->fd, fp->base, bufsize); // take the input
	}

	else if(bufsize == 1) {
		fp->ptr = base;
		fp->cnt = read(fp->fd, fp->base, bufsize);
	}

	if(--fp->cnt < 0) {
		if(fp->cnt == -1)
			return _EOF;
		if(fp->cnt == -2)
			return _ERR;
	}

	return (unsigned char)*fp->ptr++;
}
