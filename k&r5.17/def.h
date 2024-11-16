#define MAXLINES 5000
#define MAXFIELDS 10 // a maximum of 10 fields

int numcmp(void*, void*);
int strCmp(void*, void*);
int ic_strCmp(void*, void*);
int strdircmp(void*, void*);
int ic_strdircmp(void*, void*);

void Qsort(int, int, char*(*)[MAXFIELDS], int, int, int (*)(void*, void*));
void QsortR(int, int, char*(*)[MAXFIELDS], int, int, int (*)(void*, void*));

unsigned readlines(int, char*(*)[MAXFIELDS], int);
unsigned writelines(int, char*(*)[MAXFIELDS], int);
