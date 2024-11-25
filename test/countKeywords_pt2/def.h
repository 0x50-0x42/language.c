#define MAXCHAR 1000

struct key {
	char *word;
	int count;
};

int getword(char*, int);

// for better readability
struct key*
binsearch(char*, struct key*, int);
