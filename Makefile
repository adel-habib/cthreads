CC=gcc
CFLAGS=-g -pthread
SOURCES=main.c

all: my

my: $(SOURCES)
	$(CC) -o o $(SOURCES) $(CFLAGS)
clean:
	rm o.out

run:
	./o.out