IDIR = ../include
ODIR = obj

CC = gcc
CFLAGS = -g -Wall -O3 -I$(IDIR)

_DEPS = interface.h data.h files.h game.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o interface.o data.o files.o game.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f exe
