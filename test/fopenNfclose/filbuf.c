#include<stdio.h>

#include "def.h"

/* allocate and fill the input buffer */
int filbuf(_FILE *fp) {
	int bufsize;

	if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZ;

	if(fp->base == NULL)
		if((fp->base = (char*) malloc(bufsize * sizeof(char))) == NULL)
			return EOF;

	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);

	if(--fp->cnt < 0) {
		if(fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}

	return (unsigned char) *fp->ptr++;
}
