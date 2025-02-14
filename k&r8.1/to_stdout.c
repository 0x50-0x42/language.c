#include<stdio.h>
#include<unistd.h>

void to_stdout(int fd) {

	int n;

	char ch;

	// read one character at a time
	while((n = read(fd, &ch, 1)) > 0)
		write(1, &ch, n);
}
