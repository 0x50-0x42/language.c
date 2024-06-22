#include<stdio.h>

void toLower(char[]);

int main(void) {
	char string[100];

	printf("enter a string: ");
	scanf("%[^\n]%*c", string);

	toLower(string);

	printf("The string in lowercase is: %s\n", string);
	return 0;
}

void toLower(char string[]) {
	for(int i = 0; string[i] != '\0'; i++)
		string[i] = string[i] >= 'A' && string[i] <= 'Z' ? string[i] + ('a'-'A') : string[i];
}
