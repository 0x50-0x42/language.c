#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "def.h"

int _fclose(_FILE *fp) {

	if(fp == NULL)
		return 1;


	if(fp->base != NULL)
		free(fp->base);

	fp->ptr = fp->base = NULL;
	fp->cnt = 0;
	fp->flag &= 0;

	close(fp->fd);

	return 1;
}
