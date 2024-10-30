void swap(char**v1, char**v2) {
	char *temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
