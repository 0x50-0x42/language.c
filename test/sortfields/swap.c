int swap(int maxfields, char*(*str1)[maxfields], char*(*str2)[maxfields]) {
	char *temp;
	for(int i = 0; i < maxfields; i++) {

		if(*(str1[0][i]) == '\0' || *(str2[0][i]) == '\0') {
			if(i == 0) // if any of the strings has its 0th field as null char, then donot proceed any further
				return 0;
			temp = str1[0][i];
			str1[0][i] = str2[0][i];
			str2[0][i] = temp;
			break;
		}

		temp = str1[0][i];
		str1[0][i] = str2[0][i];
		str2[0][i] = temp;
	}

	return 1;
}
