#define SIZE 1000

#ifdef __MAIN__

int _getline(char*, int);
int isNum(char*);
void Help();
void entab(char*, unsigned);

#endif


#ifdef __ENTAB__

long unsigned strLen(char*);
char *alloc(unsigned);
void freeMem(char**);

#endif
