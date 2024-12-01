#define MAXCHAR 1000

struct lines {
	int val;
	struct lines *left;
	struct lines *right;
};

struct cref {
	char *word;
	struct lines *line;
	struct cref *left;
	struct cref *right;
};

#ifdef __GETWD__
int getch();
void ungetch(int);
#endif

#ifdef __MAIN__

// noise words
char list[][10] = {
	"a",
	"an",
	"and",
	"are",
	"at",
	"be",
	"been",
	"being",
	"but",
	"by",
	"did",
	"do",
	"does",
	"for",
	"had",
	"has",
	"have",
	"he",
	"if",
	"in",
	"is",
	"it",
	"no",
	"nor",
	"not",
	"of",
	"on",
	"or",
	"she",
	"so",
	"that",
	"the",
	"these",
	"they",
	"this",
	"those",
	"to",
	"was",
	"we",
	"were",
	"with"
};

int binsearch(char*, char (*)[10], int);

void freeMem();
void freeline(struct lines*);

int getword(char*, int);

struct cref*
addword(struct cref*, char *);

void printword(struct cref*);
#endif

#ifdef __ADDNODE__
void* talloc();

struct lines*
addline(struct lines*, int);
#endif

#ifdef __PRINTNODE__
void printline(struct lines*);
#endif
