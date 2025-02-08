#define MAX 1000

#define NUM '0'
#define SIN 'S'
#define COS 'C'
#define TAN 'T'
#define EXP 'E'

double stack[MAX];
int top = -1;

void push(double);
double pop();
