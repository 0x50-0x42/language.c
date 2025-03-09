#include<stdio.h>
#include<unistd.h>

#include "def.h"

int _fflush(_FILE *fp) {


	// flush the buffer into the file
	if(fp->ptr != fp->base)
		fp->cnt = write(fp->fd, fp->base, fp->cnt);
}
