#include<stdio.h>
#include<error.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct {
	int val;
	char name[20];
}sample;

int main(void) {

	sample a;

	printf("sizeof(sample): %ld\n", sizeof(a));

	int fd = open("sample.txt", O_RDONLY, 0);

	if(fd < 0)
		error(1, errno, "failed to open file...\n");

	int cnt = read(fd, (char*) &a, sizeof(a));


	char *b = (char*) &a;

	for(int i = 0; i < sizeof(a); i++)
		printf("%d ", (unsigned char)b[i]);

	printf("\nValue: %d\n", a.val);
	printf("\nString: %s\n", a.name);

	printf("\n");

	close(fd);

	return 0;
}
