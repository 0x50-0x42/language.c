#define MAXLINES 5000

int numcmp(void*, void*);
int str_cmp(void*, void*);
int str_case_cmp(void*, void*);
int strdircmp(void*, void*); // directory comparison
int strdir_case_cmp(void*, void*); // directory comparison -- case insensitive

unsigned readlines(char**, int);
void writelines(char**, int);

void qsort(char**, int, int, int(*)(void*, void*));
void qsortR(char**, int, int, int(*)(void*, void*));

void freeMem(void**);
