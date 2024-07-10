#define MAX 100

int stack[MAX];

int top = -1;

void push(int val) {

	stack[++top] = val;
}

int pop() {
	return stack[top--];
}
