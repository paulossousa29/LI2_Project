CC = gcc

INCLUDE = -I include

CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O

SRC := src

OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)
SOURCES2 := $(wildcard $(SRC)/*.c)
SOURCES := $(filter-out $(SRC)/competicao.c, $(SOURCES))
SOURCES2 := $(filter-out $(SRC)/main.c, $(SOURCES2))

NAME = program

NAME2 = bot

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
OBJECTS2 := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES2))

all: program bot

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Jogo Compilado

bot: $(OBJECTS2)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME2) $(OBJECTS2)
	@echo Bot Compilado

.PHONY: clean
clean:
	rm -r $(OBJ)
	rm -f program
	rm -f bot
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
