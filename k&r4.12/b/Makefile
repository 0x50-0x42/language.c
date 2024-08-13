files=main.o itoa.o reverse.o

run: $(files)
	gcc $(files) -o run

main.o: conv.h
	gcc -c main.c

itoa.o:
	gcc -c itoa.c

reverse.o:
	gcc -c reverse.c

.PHONY: clean

clean:
	-rm run $(files)
