/*
	write the function itob(n, s, b) that converts the integer n into a base b character 
	representation in the string s in particular, itob(n, s, 16) formats n as a hexadecimal integer in s;
*/

#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAXLEN 1000

void _itob(int, char[], int);
void reverse(char[]);

int main(void) {

	/*
		2 -> binary
		8 -> octal
		16 -> hexadecimal
	*/

	int n;

	char s[MAXLEN] = "";

	printf("enter a number: ");
	scanf("%d", &n);

	_itob(n, s, 16); // convert n to hexadecimal representation in string s

	printf("String: %s\n", s);

	return 0;
}

void reverse(char s[]) {

	int last = strlen(s) - 1; // last index of the string
	char temp;

	for(int i = last; last - i <= i; i--) {
		temp = s[last - i];
		s[last - i] = s[i];
		s[i] = temp;
	}
}

void _itob(int n, char s[], int base) {

	int idx = 0;

	switch(base) {
		case 2: // binary
			do {
				s[idx++] = n % base + '0';
				n /= base;
			}while(n != 0);

			s[idx] = '\0';

			break;
		case 8: // octal
			do {
				s[idx++] = n % base + '0';
				n /= base;
			}while(n != 0);

			s[idx++] = n + '0';
			s[idx] = '\0';

			break;
		case 16: // hex
			do {
				switch(n % base) {
					case 10:
						s[idx++] = 'a';
						break;
					case 11:
						s[idx++] = 'b';
						break;
					case 12:
						s[idx++] = 'c';
						break;
					case 13:
						s[idx++] = 'd';
						break;
					case 14:
						s[idx++] = 'e';
						break;
					case 15:
						s[idx++] = 'f';
						break;
					default:
						s[idx++] = n % base + '0';
						break;
				}

				n /= base;
			}while(n != 0);

			s[idx] = '\0';

			break;
		default: // decimal
			do {
				s[idx++] = n % 10 + '0';
				n /= 10;
			}while(n != 0);
			
			s[idx] = '\0';
			
			break;
	}

	reverse(s);
}
