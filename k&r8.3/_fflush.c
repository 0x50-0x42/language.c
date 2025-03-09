#include<stdio.h>
#include<fcntl.h>

#include "def.h"

int _fflush(_FILE *fp) {

	// flush the buffer into the file
	fp->cnt = write(fp->fd, fp->base, fp->cnt);
}
