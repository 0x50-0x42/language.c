#include<stdio.h>

#include "def.h"

int filbuf(_FILE *fp) {
	

	if((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return _EOF;
}
