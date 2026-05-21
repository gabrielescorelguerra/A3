CC = gcc
CFLAGS = -Wall -g
OBJ = player.o

#ver melhor
LIBS = $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)

all: main
# gcc main.c -o main player.o $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)
main: $(OBJ)
	$(CC) $(CFLAGS) main.c -o main $(OBJ) $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main

