struct words {
	int count;
	char *word;
	struct words *left;
	struct words *right;
};

#define MAXCHAR 1000

#ifdef __GTWD__
inline int isquote(int);
inline int isdotexclamQ(int);
inline int isfslash(int);
inline int isscore(int);

int getch();
void ungetch(int);
#endif

int getword(char*, int);
struct words*
addtree(struct words*, char*, int);
