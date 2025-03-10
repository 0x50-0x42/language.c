#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

int filbuf(_FILE *fp, long numChar) {

	if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return _EOF;

	int bufsize = (fp->flag & _UNBUF) ? 1 : numChar;

	if(fp->base == NULL) {
		if(!(fp->base = calloc(bufsize, sizeof(char))))
			return _ERR;
		fp->ptr = fp->base;
		fp->cnt = read(fp->fd, fp->base, bufsize);
	}

	if(bufsize == 1) {
		fp->ptr = fp->base;
		fp->cnt = read(fp->fd, fp->base, bufsize);
	}

	if(--fp->cnt < 0) {
		if(fp->cnt == -1)
			return _EOF;
		else
			return _ERR;
	}

	return _READ; // return the flag
}
