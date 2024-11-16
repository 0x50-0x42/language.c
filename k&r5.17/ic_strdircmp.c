#include<ctype.h>

int ic_strdircmp(void*s1, void*s2) {
	char*str1 = s1;
	char*str2 = s2;

	if((*str1 >= 33 && *str1 <= 47) || (*str1 >= 58 && *str1 <= 64) || (*str1 >= 91 && *str1 <= 96) || *str1 >= 123 && *str1 <= 126)
		while(!isdigit(*str1) && !isalpha(*str1) && !isspace(*str1))
			str1++;

	if((*str2 >= 33 && *str2 <= 47) || (*str2 >= 58 && *str2 <= 64) || (*str2 >= 91 && *str2 <= 96) || *str2 >= 123 && *str2 <= 126)
		while(!isdigit(*str2) && !isalpha(*str2) && !isspace(*str2))
			str2++;

	while(tolower(*str1) == tolower(*str2)) {
		if(*str1 == '\0' || *str1 == '\0')
			return *str1 - *str2;

		str1++, str2++;

		if((*str1 >= 33 && *str1 <= 47) || (*str1 >= 58 && *str1 <= 64) || (*str1 >= 91 && *str1 <= 96) || *str1 >= 123 && *str1 <= 126)
			while(!isdigit(*str1) && !isalpha(*str1) && !isspace(*str1))
				str1++;
		if((*str2 >= 33 && *str2 <= 47) || (*str2 >= 58 && *str2 <= 64) || (*str2 >= 91 && *str2 <= 96) || *str2 >= 123 && *str2 <= 126)
			while(!isdigit(*str2) && !isalpha(*str2) && !isspace(*str2))
				str2++;
	}

	return *str1 - *str2;
}
