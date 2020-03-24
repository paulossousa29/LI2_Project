// Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define

#define MAX 40
#define SMAX 20

// Structs

typedef enum {
    VAZIO, 
    BRANCA, 
    PRETA
} CASA;

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

typedef struct {
    int validas;
    COORDENADA coords[8];
} CVAL;

// Functions

void gamestart(ESTADO *e);
int jogAtual(ESTADO *e);
void alteraJog(ESTADO *e, int jog);
int numJogadas(ESTADO *e);
void incJogadas(ESTADO *e);
CASA estadoCasa(ESTADO *e, int col, int linha);
void alteraCasa(ESTADO *e, CASA a, int col, int linha);
int ultimaJogLinha(ESTADO *e);
int ultimaJogColuna(ESTADO *e);
void alteraUltimaJog(ESTADO *e, int linha, int col);