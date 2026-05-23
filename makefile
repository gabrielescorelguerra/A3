CC = gcc
CFLAGS = -Wall -g
ALLEGRO_FLAGS = $(shell pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 --libs --cflags)

OBJ = player.o
SOURCES = player.c main.c
TARGET = main

# gcc main.c -o main player.o $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)
all:
	gcc $(SOURCES) -o $(TARGET) $(ALLEGRO_FLAGS)

clean:
	rm -f *.o main
