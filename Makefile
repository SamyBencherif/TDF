
CC=gcc
CFLAGS=-std=c89 -Wall -Werror -Wpendantic -v

main main.c object-model.h device-config.h:
	$(CC) $(CFLAGS) -o main main.c

