/*
	write the function htoi(), which converts a string of hexadecimal
	digits(including otional 0x or 0X) into its equivalent integer value;
	the allowable digits are 0 through 9, a through f and A through F
 */


#include<stdio.h>
#include<math.h>
#include<string.h>

int htoi(char*);

int main(void) {
	char hex[100];

	printf("enter hex number: ");
	scanf("%[^\n]%*c", hex);

	int a = htoi(hex);
	printf("Result in decimal: %d\n", a);
	return 0;
}

int htoi(char*hexStr) {

	int intResult = 0;
	int len = strlen(hexStr);

	for(int i = 0; hexStr[i] != '\0'; i++) {
		if(hexStr[i] == '0' && i != len - 1 && (hexStr[i + 1] == 'x' || hexStr[i] == 'X'))
			continue;
		if(hexStr[i] >='0' && hexStr[i] <= '9')
			intResult = intResult + ((hexStr[i] - '0')*pow(16, (len - 1) - i));
		else if(hexStr[i] >= 'a' && hexStr[i] <= 'f')
			intResult = intResult + ((hexStr[i] - 'W')*pow(16, (len - 1) - i));
		else if(hexStr[i] >= 'A' && hexStr[i] <= 'F')
			intResult = intResult + ((hexStr[i] - '7')*pow(16, (len - 1) - i));
	}

	return intResult;
}
