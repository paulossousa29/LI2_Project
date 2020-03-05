IDIR = ../include
ODIR = obj

CC = gcc
CFLAGS = -g -Wall -O3 -I$(IDIR)

_DEPS = headers.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o menu.o state.o files.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f exe
