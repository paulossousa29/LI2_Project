CC = gcc

INCLUDE = -I include

CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O -g

SRC := src

OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

NAME = bot

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

bot: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Bot Compilado

.PHONY: clean
clean:
	rm -r $(OBJ)
	rm -f bot
	@echo Objetos e Executáveis Apagados

.PHONY: help
help:
	@echo "src: $(SOURCES)"
	@echo "obj: $(OBJECTS)"

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(shell mkdir -p $(OBJ))
