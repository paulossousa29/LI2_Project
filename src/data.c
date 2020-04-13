#include "data.h"

struct coordenanda{
    int coluna;
    int linha;
};

struct jogada{
    COORDENADA jogador1;
    COORDENADA jogador2;
};

struct estado{
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
};

struct cval{
    int validas;
    COORDENADA coords[8];
};

void gamestart(ESTADO *e) {
    int i, j;

    for(i=0; i<8; i++)
      for(j=0; j<8; j++)
        e->tab[i][j] = VAZIO;

    e->tab[3][4] = BRANCA;

    e->ultima_jogada.linha = 5;
    e->ultima_jogada.coluna = 4;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
}

int jogAtual(ESTADO *e) {
  return e->jogador_atual;
}

void alteraJog(ESTADO *e, int jog) {
  e->jogador_atual = jog;
}

int numJogadas(ESTADO *e) {
  return e->num_jogadas;
}

void incJogadas(ESTADO *e) {
  e->num_jogadas++;
}

CASA estadoCasa(ESTADO *e, int linha, int col) {
  return e->tab[linha][col];
}

void alteraCasa(ESTADO *e, CASA a, int linha, int col) {
  e->tab[linha][col] = a;
}

int ultimaJogLinha(ESTADO *e) {
  return e->ultima_jogada.linha;
}

int ultimaJogColuna(ESTADO *e) {
  return e->ultima_jogada.coluna;
}

void alteraUltimaJog(ESTADO *e, int linha, int col) {
  e->ultima_jogada.linha = linha;
  e->ultima_jogada.coluna = col;
}

int getJog1Col(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador1.coluna;
}

int getJog1Line(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador1.linha;
}

int getJog2Col(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador2.coluna;
}

int getJog2Line(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador2.linha;
}

int getCol(COORDENADA* c) {
  return c->coluna;
}

int getLine(COORDENADA* c) {
  return c->linha;
}

int getValidas(CVAL* cr) {
  return cr->validas;
}

COORDENADA getCoord(CVAL* cr, int i) {
  return cr->coords[i];
}

COORDENADA getJogada1(ESTADO* e, int i) {
  return e->jogadas[i].jogador1;
}

COORDENADA getJogada2(ESTADO* e, int i) {
  return e->jogadas[i].jogador2;
}