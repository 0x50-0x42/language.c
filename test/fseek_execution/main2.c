#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv) {
	if(argc == 1)
		error(1, errno, "filename required as argument...\n");

	int fd = open(argv[1], O_RDONLY, 0);

	if(fd < 0)
		error(1, errno, "failed to open file...\n");

	char buffer[1000];

	int cnt = read(fd, buffer, 10);
	printf("%s\n", buffer);

	lseek(fd, 10L, 1);

	cnt = read(fd, buffer, 10);
	printf("%s\n", buffer);

	close(fd);

	return 0;
}
