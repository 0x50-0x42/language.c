#include<stdio.h>
#include<unistd.h>
#include "def.h"

int _fflush(_FILE *fp) {

	if(fp == NULL)
		return 0;

	if(fp->base == NULL)
		return 0;

	fp->cnt = write(fp->fd, fp->base, fp->cnt);

	return 1;
}
