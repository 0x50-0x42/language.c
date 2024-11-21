// store the last allocated memory

#define MAXMEM 10000

static int alloced[MAXMEM];
static int idx = 0;

void storeMem(unsigned val) {
	alloced[idx++] = val;
}

int getMem() {
	if(idx < 0)
		return -1;
	return alloced[--idx];
}
