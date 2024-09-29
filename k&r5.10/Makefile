files=main.c parse.c stack.c def.h

expr: $(files)
	gcc -g $(files) -o expr -lm

.PHONY: clean

clean:
	-rm expr
