// Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define

#define MAX 40
#define SMAX 20

typedef enum {
    VAZIO, 
    BRANCA, 
    PRETA
} CASA;

typedef struct coordenanda COORDENADA;
typedef struct jogada JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct estado ESTADO;
typedef struct cval CVAL;

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
int getJog1Col(ESTADO* e, int i);
int getJog1Line(ESTADO* e, int i);
int getJog2Col(ESTADO* e, int i);
int getJog2Line(ESTADO* e, int i);
int getCol(COORDENADA* c);
int getLine(COORDENADA* c);
int getValidas(CVAL* cr);
COORDENADA getCoord(CVAL* cr, int i);
COORDENADA getJogada1(ESTADO* e, int i);
COORDENADA getJogada2(ESTADO* e, int i);