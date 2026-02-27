CC = gcc
CFLAGS = -Wall -Wextra -O2
INCLUDE = -Iinclude
SRC = main.c src/*.c
OUT = cnet

all: $(OUT)

$(OUT):
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $(OUT)

install: $(OUT)
	cp $(OUT) /usr/local/bin/

clean:
	rm -f $(OUT)
