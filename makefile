CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
TARGET = simple_shell

all: $(TARGET)

$(TARGET): main.c shell.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
