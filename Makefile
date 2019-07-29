CC=gcc#
CFLAGS=-std=c89 -Wall -Werror -Wpedantic -v#
AR=ar#
ARFLAGS=-rs#

main src/* include/*:
	$(CC) $(CFLAGS) -Iinclude -o bin/main src/main.c \
									src/object-model.c src/device-ins.c
