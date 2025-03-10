#include<stdio.h>
#include<unistd.h>

#include "def.h"

int _fseek(_FILE *fp, long offset, int whence) {

	// check the flag of the file pointer
	if((fp->flag & (_READ | _WRITE)) == _READ) { // when file is opened in reading mode
		// when reading, the file pointer's position is the current position
		if(whence == 1) {
			fp->ptr = fp->base; // reset ptr; discard the previously stored contents in the buffer (if any)
			if(lseek(fp->fd, offset, whence) < 0)
				return -1;
		}

		else // position other than the current position
			return -1;
	}

	else if((fp->flag & (_READ | _WRITE)) == _WRITE) { // when file is opened in writing mode
		// if the buffer is unflushed then
		if(fp->ptr != fp->base)
			_fflush(fp); // flush the buffer
		if(whence == 0 || whence == 1 || whence == 2) {
			if(lseek(fp->fd, offset, whence) < 0) // place the pointer in the required position
				return -1;
		}
	}

	else
		return -1; // unknown flag

	return 0;
}
