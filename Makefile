CC = gcc

INCLUDE = -I include

CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O

SRC := src

OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

NAME = program

NAME2 = bot

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: program bot
	doxygen Doxyfile
	@echo Documentação gerada

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Jogo Compilado

bot: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME2) $(OBJECTS)
	@echo Bot Compilado

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
