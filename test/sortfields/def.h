#define MAXLINES 5000
#define MAXFIELDS 3

void qsort(int, char*(*)[MAXFIELDS], int, int, int);

unsigned readlines(int, char*(*)[MAXFIELDS], int);
void writelines(int, char*(*)[MAXFIELDS], int);
