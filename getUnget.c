#define BUFFSIZE 100

int bufp;

char buffer[BUFFSIZE];

int getch(void) {

	// if the buffer contains anything then return this otherwise take user input
	return bufp > 0 ? buffer[--bufp] : getchar();
}

void ungetch(int c) {
}
