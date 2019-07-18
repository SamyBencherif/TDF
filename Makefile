
CC=gcc
CFLAGS=-std=c89 -Wall -Werror -v

main main.c object-model.h device-config.h:
	$(CC) $(CFLAGS) -o main main.c

