main: main.c 
	gcc -g -Wall -Wextra -Wpedantic -o main main.c $(shell pkg-config --cflags --libs gpgme)
