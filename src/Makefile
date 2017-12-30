CC = gcc
CFLAGS = `sdl2-config --libs --cflags` -O0 --std=c11 -Wall -lSDL2_image -lSDL2_ttf -lm
LFLAGS = `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -lm
EXEC = tp3
AUXI_IMPL = $(filter-out  $(EXEC).c,$(wildcard *.c))
AUXI_OBJS = $(patsubst %.c,%.o,$(AUXI_IMPL))

$(EXEC): $(AUXI_OBJS) $(EXEC).o
	$(CC) $(EXEC).o $(AUXI_OBJS) $(LFLAGS) -o $(EXEC)

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean test

clean:
	rm -f *.o
	rm -rf $(EXEC)

