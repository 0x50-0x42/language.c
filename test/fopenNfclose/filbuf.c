#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include "def.h"

/* allocate and fill the input buffer */
int filbuf(_FILE *fp) {
	int bufsize;

	if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return _EOF;

	/* Combining the flags _READ, _EOF and _ERR using bitwise OR gives us the following result:
	 *
	 * 000000001
	 * 000001000
	 * 000010000
	 * ---------
	 * 000011001
	 *
	 * So, if one of _READ, _EOF or _ERR flags were to be bitwise AND-ed with this result
	 * then it would produce that same flag
	 *
	 * Example: _READ AND-ed with the result would be:
	 *
	 * 000000001
	 * 000011001
	 * ---------
	 * 000000001 -> _READ flag
	*/

	bufsize = (fp->flag & _UNBUF) ? 1 : _BUFSIZ;

	// if the buffer is NULL
	if(fp->base == NULL) {
		// then allocate memory
		if((fp->base = (char*) malloc(bufsize * sizeof(char))) == NULL)
			return _EOF;

		// and set the next character position to the (address of) the 0th character in the buffer
		fp->ptr = fp->base;

		// read in the string and record its character count
		fp->cnt = read(fp->fd, fp->ptr, bufsize);
	}

	// reduce the character count to check if empty string was entered
	if(--fp->cnt < 0) { // this also serves as string-ended condition when filbuf() is called repeatedly
		if(fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return _EOF;
	}

	// return one character from the buffer and advance the position to the next character's position
	return (unsigned char) *fp->ptr++;
}
