files=main.c handleArgs.c sorted.c getline.c entab.c def.h

entab: $(files)
	gcc -g $(files) -o entab

.PHONY: clean

clean:
	-rm entab
