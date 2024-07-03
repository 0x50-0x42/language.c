// An experiment with continue inside a switch inside a while

#include<stdio.h>


int main(void) {

	int i = 1;
	while(i <= 10) {
		switch(i) {
			case 1:
				puts("one");
				continue;
			case 2:
				puts("two");
				continue;
			case 3:
				puts("three");
				continue;
			case 4:
				puts("four");
				continue;
			case 5:
				puts("five");
				continue;
			case 6:
				puts("six");
				continue;
			case 7:
				puts("seven");
				continue;
			case 8:
				puts("eight");
				continue;
			case 9:
				puts("nine");
				continue;
			case 10:
				puts("ten");
				continue;
		}

		i++;
	} // an infinite loop which only displays "one"

	return 0;
}