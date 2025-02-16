#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define PERMS 0666 /* premissions for owner, group and all others */

#include "def.h"

_FILE *_fopen(char *filename, char *mode) {

	int fd;
	_FILE *fp;

	// check the mode
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;

	// find a file pointer whose flag is empty/0
	for(fp = iob; fp < iob + OPEN_MAX; fp++)
		if((fp->flag & (_READ | _WRITE)) == 0)
			break;

	// if there was no file pointer with an empty flag
	if(fp >= iob + OPEN_MAX)
		return NULL; // then abort


	// open the file as per the mode passed to _fopen()
	if(*mode == 'w') // write mode
		fd = creat(filename, PERMS);
	else if(*mode == 'a') { // append mode
		if((fd = open(filename, O_WRONLY, 0)) < 0) // if the file doesn't exist then
			fd = creat(filename, PERMS); // create the file
		lseek(fd, 0L, 2); // set the current position to the end of the file
	}
	
	else { // read mode
		if((fd = open(filename, O_RDONLY, 0)) < 0)
			return NULL;
	}

	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;

	return fp;
}
