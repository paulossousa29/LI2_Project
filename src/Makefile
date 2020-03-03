IDIR = ../include
ODIR = obj

CC = gcc
CFLAGS = -g -Wall -O3 -I$(IDIR)

_DEPS = estado.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = estado.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f exe
