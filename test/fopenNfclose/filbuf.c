#include<stdio.h>

#include "def.h"

/* allocate and fill the input buffer */
int filbuf(_FILE *fp) {
	int bufsize;

	if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZ;

	if(fp->base == NULL) {
	}
}
