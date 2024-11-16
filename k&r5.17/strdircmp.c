#include<ctype.h>

int strdircmp(void*s1, void*s2) {
	char*str1 = s1;
	char*str2 = s2;

	if((*str1 >= '!' && *str1 <= '/') || (*str1 >= ':' && *str1 <= '@') || (*str1 >= '[' && *str1 <= '`') || *str1 >= '{' && *str1 <= '~')
		while(!isdigit(*str1) && !isalpha(*str1) && !isspace(*str1))
			str1++;

	if((*str2 >= '!' && *str2 <= '/') || (*str2 >= ':' && *str2 <= '@') || (*str2 >= '[' && *str2 <= '`') || *str2 >= '{' && *str2 <= '~')
		while(!isdigit(*str2) && !isalpha(*str2) && !isspace(*str2))
			str2++;

	while(*str1 == *str2) {
		if(*str1 == '\0' || *str1 == '\0')
			return *str1 - *str2;

		str1++, str2++;

		if((*str1 >= '!' && *str1 <= '/') || (*str1 >= ':' && *str1 <= '@') || (*str1 >= '[' && *str1 <= '`') || *str1 >= '{' && *str1 <= '~')
			while(!isdigit(*str1) && !isalpha(*str1) && !isspace(*str1))
				str1++;
		if((*str2 >= '!' && *str2 <= '/') || (*str2 >= ':' && *str2 <= '@') || (*str2 >= '[' && *str2 <= '`') || *str2 >= '{' && *str2 <= '~')
			while(!isdigit(*str2) && !isalpha(*str2) && !isspace(*str2))
				str2++;
	}

	return *str1 - *str2;
}
