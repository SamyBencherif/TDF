
CC=gcc
CFLAGS=-std=c89 -Wall -Werror -v

# The default build profile is merely a convenience.
# If this doesn't work on your system, run ``make main''.
default main.c object-model.h device-config.h:
	@sh compile.sh

main:
	$(CC) $(CFLAGS) -o main main.c

test-png:
	$(CC) $(CFLAGS) -o test-png test-png.c -lpng
