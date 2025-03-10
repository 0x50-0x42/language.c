#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv) {
	if(argc == 1)
		error(1, errno, "file name required...\n");

	int fd = open(argv[1], O_RDONLY, 0);

	if(fd < 0)
		error(1, errno, "failed to open file...\n");

	char buffer[1000] = {'\0'};

	int cnt = read(fd, buffer, 10);

	printf("%s\n", buffer);

	int fd2 = creat("written.txt", 0666);

	cnt = write(fd2, buffer, cnt);

	close(fd);
	close(fd2);

	return 0;
}
