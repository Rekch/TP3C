CC = gcc
CFLAGS = -g -std=c11 -W -Wall ${SDL}
EXEC = tp3
SDL = -lSDLmain -lSDL -lSDL_image -lSDL_ttf
AUXI_IMPL = $(filter-out $(EXEC).c,$(wildcard *.c))
AUXI_OBJS = $(patsubst %.c,%.o,$(AUXI_IMPL))

$(EXEC): $(AUXI_OBJS) $(EXEC).o
	$(CC) $(EXEC).o $(AUXI_OBJS) -o $(EXEC)

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean 

clean:
	rm -f *.o
	rm -rf $(EXEC)

