#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "def.h"

int _fclose(_FILE *fp) {

	if(fp->base != NULL)
		free(fp->base);

	fp->base = fp->ptr = NULL;
	fp->cnt = 0;
	fp->flag &= 0;

	close(fp->fd);

	fp = NULL;

	return 1;
}
