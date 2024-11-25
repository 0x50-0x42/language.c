#define MAXCHAR 1000

struct key {
	char *word;
	int count;
};

int getword(char*, int);
int binsearch(char*, struct key*, int);
