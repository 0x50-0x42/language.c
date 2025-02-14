#include<stdio.h>
#include<fcntl.h> // for O_RDONLY, O_WRONLY and O_RDWR
#include<error.h> // for error()
#include<errno.h> // for errno
#include<unistd.h> // for read() and write()

int main(void) {

	int fd;

	const char* filename = "text.txt";

	// create the file
	if((fd = creat(filename, 0711)) < 0) {
		error(1, errno, "failed to create file!");

		return 1;
	}

	// open the file for writing
	fd = open(filename, O_WRONLY, 0);

	puts("enter some text:\n");

	char string[1000];

	int n = read(0, string, 1000);

	// write the contents of string into the file using the file descriptor returned by open()
	write(fd, string, n);

	// disconnect the file descriptor from the file
	close(fd); // fd is available for re-use with another file now

	return 0;
}
