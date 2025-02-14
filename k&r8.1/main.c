#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(int argc, char **argv) {

	if(argc == 1)
		error(1, errno, "No files provided...");

	int fd;

	for(int i = 1; i < argc; ++i) {
		if((fd = open(argv[i], O_RDONLY, 0)) < 0)
			error(1, errno, "file doesn't exist!");

		to_stdout(fd);

		close(fd); // make fd available for use with another file
	}

	return 0;
}
