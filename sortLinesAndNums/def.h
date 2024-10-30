#define MAXLINES 5000

unsigned _getline(char*, int);
unsigned readlines(char**, int);
void writelines(char**, int);

int numcmp(void*, void*);
int strCmp(void*, void*);

void freeMem(void*);
void qsort(char**, int, int, int(*)(void*, void*));
