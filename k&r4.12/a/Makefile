files=main.o itoa.o

run: $(files)
	gcc $(files) -o run

itoa.o:
	gcc -c itoa.c

main.o:
	gcc -c main.c

.PHONY: clean

clean:
	-rm run $(files)
