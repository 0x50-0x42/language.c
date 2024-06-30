run: $(f)
	gcc $(f) -o run

.PHONY: clean

clean:
	-rm run
