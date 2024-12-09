struct nlist {
	char *name;
	char *defn;
	struct nlist *next;
};

#ifdef __CONST__
#define HASHSIZE 101
#define MAXCHAR 1000
#endif

#ifdef __MAIN__
int getword(char*, int);
void install(char*, char*);
void displaytable();
void freeMem();
#endif

#ifdef __GETWD__
int getch();
void ungetch(int);

inline int ishash(int);
inline int isscore(int);
#endif

#ifdef __INSTALL__
unsigned hash(char*);
struct nlist *lookup(char*);
#endif
