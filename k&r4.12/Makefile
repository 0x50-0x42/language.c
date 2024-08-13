files=main.o itoa.o

run: $(files)
	gcc $(files) -o run

main.o:
	gcc -c main.c

itoa.o:
	gcc -c itoa.c

.PHONY: clean

clean:
	-rm run $(files)
