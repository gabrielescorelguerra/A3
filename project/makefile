CC = gcc
CFLAGS = -Wall -g
ALLEGRO_FLAGS = -mmacosx-version-min=26 $(shell pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 allegro_image-5 --libs --cflags)

SRC_DIR = src
SRC = $(SRC_DIR)/player.c $(SRC_DIR)/joystick.c $(SRC_DIR)/movement.c $(SRC_DIR)/main.c 

TARGET = main

all:
	gcc $(SRC) -Iinclude -o $(TARGET) $(ALLEGRO_FLAGS)

clean:
	rm -f *.o main
