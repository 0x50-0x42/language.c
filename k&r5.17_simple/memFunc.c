#include<stdio.h>
#include<string.h>

#define MAXMEM 10000

char mem[MAXMEM];
char *byte = mem;

void storeMem(unsigned);
int getMem();

void* alloc(unsigned reqMem) {

	if(reqMem >= MAXMEM)
		return NULL;
	if(MAXMEM - (byte - mem) <= reqMem)
		return NULL;

	void*temp = NULL;

	byte += reqMem;
	temp = byte - reqMem;
	storeMem(reqMem);

	byte++;

	return temp;
}

void freeMem() {
	if(byte - mem == 0)
		return;

	byte--;

	int Mem = getMem();

	if(Mem < 0)
		return;
	byte -= Mem;
}
