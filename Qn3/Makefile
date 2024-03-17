# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=iso9899:2018 -pedantic

# PAPI library
PAPI_LIB = -lpapi

# Output executable
OUTPUT = output

# Source files
SRC = main.c

all: $(OUTPUT)

$(OUTPUT): main.o
	$(CC) $(CFLAGS) -o $@ $^ $(PAPI_LIB)

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(OUTPUT)
