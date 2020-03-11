// Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define

#define MAX 40
#define SMAX 20

// Structs
/*
typedef enum {EMPTY, CURRENT, OCCUPIED} VALUE;

typedef struct coord
{
  int line;
  int col;
} COORD;

typedef struct state
{
    int player;
    COORD curr;
    VALUE table[8][8];
} STATE;
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;
// Functions

void place(ESTADO* e, COORDENADA* c, char* col, char* line);

void input(ESTADO* e, char* name);
void output(ESTADO* e, char* name);

void printa(ESTADO *e);
void gamestart(ESTADO *e);

void menu();
void execute(char* buffer, ESTADO* e, COORDENADA* c);
