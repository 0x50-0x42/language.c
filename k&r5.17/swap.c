void swap(char**s1, char**s2, int maxfields) {
	char *temp;

	for(int i = 0; i < maxfields; i++) {
		if((*s1[i] == '\0' || *s2[i] == '\0') && i == 0)
			return;
		if((*s1[i] == '\0' || *s2[i] == '\0') && i != 0) {
			temp = s1[i];
			s1[i] = s2[i];
			s2[i] = temp;
			return;
		}

		temp = s1[i];
		s1[i] = s2[i];
		s2[i] = temp;
	}
}
