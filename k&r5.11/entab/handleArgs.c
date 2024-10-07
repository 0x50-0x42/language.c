#include<stdio.h>
#include<stdlib.h>

extern unsigned tabs;

void handleArgs(int *argNum, char*** argVec) {

	while(*argNum != 0 && ***argVec == '-') {
		while(*(++**argVec) != '\0' && ***argVec != ' ' && !(***argVec >='0' && ***argVec <='9')) { // won't accept options in quotations
			switch(***argVec) {
				case 'h':
					puts("Convert spaces to tabs");
					puts("entab [OPTION] tab1,[tab2, ...tabn] [text] [-]");
					puts("OPTION:");
					puts("-t N      have tabs N characters apart.");
					puts("-h        display this help and exit.");
					exit(0);

				case 't':
					if(tabs) {
						puts("Invalid option!");
						return;
					}

					tabs = 1;
					break;

				default:
					puts("Invalid option");
					return;
			}
		}

		if(***argVec == ' ' || (***argVec >='0' && ***argVec <='9')) {
			puts("invalid option");
			return;
		}

		(*argVec)++;
		(*argNum)--;
	}

}
