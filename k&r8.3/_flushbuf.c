#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

// flushes the buffer into the output file
int _flushbuf(int c, _FILE *fp) {

	// check if the file pointer has write flag enabled
	if(*fp->flag & (_WRITE | _EOF | _ERR) != _WRITE)
		return _EOF;

	int bufsize = _BUFSIZ;

	// check the buffer
	if(fp->base == NULL) {
		if(!(fp->base = calloc(bufsize, sizeof(char))))
			return _ERR;
		fp->ptr = base;
	}

	fp->cnt++;

	*fp->ptr++ = c;

	return 1;
}
