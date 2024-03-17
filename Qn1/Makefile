# CFLAGS = -Wall -std=iso9899:2018 -pedantic
CFLAGS = -Wall -std=c11 -pedantic

output: main.o 
	gcc $(CFLAGS) main.o -o output

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o output
