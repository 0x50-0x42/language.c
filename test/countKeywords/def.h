#define MAXCHAR 1000
#define MAXKWORD 32

struct keyword {
	char *name;
	int count;
};

int getword(char*, int);
