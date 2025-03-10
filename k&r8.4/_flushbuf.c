#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

int _flushbuf(int c, _FILE *fp) {

	if((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
		return _EOF;

	int bufsize = _BUFSIZ;

	// check if the buffer is unallocated
	if(fp->base == NULL) {
		// if it is, then allocate memory to it
		if(!(fp->base = calloc(bufsize, sizeof(char))))
			return _EOF;
		fp->ptr = fp->base; // and set ptr to base
	}

	// keep storing one character at a time into the buffer
	fp->cnt++;
	*fp->ptr++ = c;

	// if there is a newline in the text, then write the whole text into the file
	if(c == '\n') {
		fp->cnt = write(fp->fd, fp->base, fp->cnt);
		fp->ptr = fp->base; // reset ptr
		fp->cnt = 0; // reset the counter
	}

	return 1;
}
