CC=gcc
FLAGS=-std=c17 -g

all: clean cli serv

clean:
	rm *.out

cli:
	$(CC) $(FLAGS) $@.c -o $@.out

serv:
	$(CC) $(FLAGS) $@.c -o $@.out