#ifdef __MAIN__
#define SIZE 1000

int _getline(char*, int);
void rmCom(char*);

#else
#ifdef __RMCOM__
#define multCom(s) {\
	if(*s == '/') {\
		if(*(s + 1) == '*')\
			s += 2;\
	}\
	else if(*s == '*') {\
		if(*(s + 1) == '/')\
			s += 2;\
	}\
}

#define singleCom(s) {\
	if(*s == '/') {\
		if(*(s + 1) == '/') \
			s += 2;\
	}\
}

#endif
#endif
