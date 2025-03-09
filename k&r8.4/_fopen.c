#include<stdio.h>

#include "def.h"

_FILE *_fopen(char *filename, char *mode) {

	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;

	_FILE *fp = _iob;

	// check for empty file pointers
	for(; fp - _iob < OPEN_MAX; fp++)
		if((fp->flag & (_READ | _WRITE)) == 0)
			break;

	if(fp - _iob >= OPEN_MAX)
		return NULL;

	int bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZ;

	// checking buffer status
	if(fp->base == NULL)
		if(!(fp->base = calloc(bufsize, sizeof(char))))
}
