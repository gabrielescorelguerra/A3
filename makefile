CC = gcc
CFLAGS = -Wall -g
ALLEGRO_FLAGS = -mmacosx-version-min=26 $(shell pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 --libs --cflags)

SOURCES = player.c joystick.c movement.c main.c 
TARGET = main

# gcc main.c -o main player.o $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)
all:
	gcc $(SOURCES) -o $(TARGET) $(ALLEGRO_FLAGS)

clean:
	rm -f *.o main
