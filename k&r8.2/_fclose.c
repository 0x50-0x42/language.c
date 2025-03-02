#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

_FILE* _fclose(_FILE *fp) {
	if(fp == NULL)
		return NULL;
	fp->cnt = 0; // reset the character count
	fp->ptr = NULL;
	if(fp->base != NULL) // clear the buffer
		free(fp->base);

	// reset the flags
	fp->_READ = fp->_WRITE = fp->_UNBUF = fp->_EOF = fp->_ERR = 0;

	if(close(fp->fd) < 0) // disconnect the file descriptor from the file
		error(1, errno, "failed to close the file...\n");

	fp = NULL;

	return fp;
}
