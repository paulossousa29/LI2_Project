CC = gcc

INCLUDE = -I include

CFLAGS = -O3 -Wall -g

SRC := src

OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

NAME = program

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Compilado

all: program
	doxygen Doxyfile
	@echo Documentação gerada

.PHONY: clean
clean:
	rm -r $(OBJ)
	rm -f program
	@echo Objetos e Executável Apagados

.PHONY: cleanall
cleanall: clean
	rm -r docs/html
	@echo Documentação Apagada

.PHONY: help
help:
	@echo "src: $(SOURCES)"
	@echo "obj: $(OBJECTS)"

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(shell mkdir -p $(OBJ))
