// Includes
#ifndef __data_h
#define __data_h

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

typedef struct coordenada{
    int coluna;
    int linha;
}COORDENADA;

typedef struct jogada{
    COORDENADA jogador1;
    COORDENADA jogador2;
}JOGADA;
typedef JOGADA JOGADAS[32];

typedef struct estado{
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
}ESTADO;

// Functions

void gamestart(ESTADO *e);
ESTADO* initEstado();
COORDENADA* initCoordenada();
COORDENADA* duplicaCOORD(COORDENADA *c);

void setJogAtual(ESTADO *e, int jog);
void setNJogadas(ESTADO *e,int n);
void setCasa(ESTADO *e, CASA a, int col, int linha);
void setUltimaJog(ESTADO *e, int linha, int col);
void setJog1(ESTADO* e, int i, int line, int col);
void setJog2(ESTADO* e, int i, int line, int col);
void setCoord(COORDENADA* c, int line, int col);
//int getValidas(CVAL* cr);
//COORDENADA getCoord(CVAL* cr, int i);
int getjogAtual(ESTADO *e);
int getnumJogadas(ESTADO *e);
int getCol(COORDENADA* c);
int getLine(COORDENADA* c);
CASA getCasa(ESTADO *e, int col, int linha);
int getultimaJogLinha(ESTADO *e);
int getultimaJogColuna(ESTADO *e);
int getJog1Col(ESTADO* e, int i);
int getJog1Line(ESTADO* e, int i);
int getJog2Col(ESTADO* e, int i);
int getJog2Line(ESTADO* e, int i);
COORDENADA getJogada1(ESTADO* e, int i);
COORDENADA getJogada2(ESTADO* e, int i);

#endif
