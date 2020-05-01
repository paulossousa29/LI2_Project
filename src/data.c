#include "data.h"

void gamestart(ESTADO *e) {
    int i, j;

    for(i=0; i<8; i++)
      for(j=0; j<8; j++)
        e->tab[i][j] = VAZIO;

    e->tab[3][4] = BRANCA;

    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
}


ESTADO* initEstado() {
  ESTADO* new = malloc(sizeof(ESTADO));

  return new;
}

COORDENADA* initCoordenada() {
  COORDENADA* new = malloc(sizeof(COORDENADA));

  return new;
}

COORDENADA* duplicaCOORD(COORDENADA *c) {
  COORDENADA *new = malloc(sizeof(COORDENADA));
  new -> linha = c -> linha;
  new -> coluna = c -> coluna;

  return new;
}

ESTADO* duplicaEstado(ESTADO* e) {
  int i, j;
  
  ESTADO* new = malloc(sizeof(ESTADO));

  new->num_jogadas = e->num_jogadas;
  new->jogador_atual = e->jogador_atual;
  new->ultima_jogada.linha = e->ultima_jogada.linha;
  new->ultima_jogada.coluna = e->ultima_jogada.coluna;

  for(i=0; i<7; i++)
    for(j=0; j<7; j++)
      new->tab[i][j] = e->tab[i][j];

  for(i=0; i<new->num_jogadas; i++) {
    new->jogadas[i].jogador1.linha = e->jogadas[i].jogador1.linha;
    new->jogadas[i].jogador1.coluna = e->jogadas[i].jogador1.coluna;
    new->jogadas[i].jogador2.linha = e->jogadas[i].jogador2.linha;
    new->jogadas[i].jogador2.coluna = e->jogadas[i].jogador2.coluna;
  }

  return new;
}

int getjogAtual(ESTADO *e) {
  return e->jogador_atual;
}

void setJogAtual(ESTADO *e, int jog) {
  e->jogador_atual = jog;
}

int getnumJogadas(ESTADO *e) {
  return e->num_jogadas;
}

void setNJogadas(ESTADO *e,int n) {
  e->num_jogadas = n;
}

CASA getCasa(ESTADO *e, int linha, int col) {
  return e->tab[linha][col];
}

void setCasa(ESTADO *e, CASA a, int linha, int col) {
  e->tab[linha][col] = a;
}

int getultimaJogLinha(ESTADO *e) {
  return e->ultima_jogada.linha;
}

int getultimaJogColuna(ESTADO *e) {
  return e->ultima_jogada.coluna;
}

void setUltimaJog(ESTADO *e, int linha, int col) {
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

void setJog1(ESTADO* e, int i, int line, int col) {
  e->jogadas[i-1].jogador1.linha = line;
  e->jogadas[i-1].jogador1.coluna = col;
}

void setJog2(ESTADO* e, int i, int line, int col) {
  e->jogadas[i-1].jogador2.linha = line;
  e->jogadas[i-1].jogador2.coluna = col;
}

int getCol(COORDENADA* c) {
  return c->coluna;
}

int getLine(COORDENADA* c) {
  return c->linha;
}

void setCoord(COORDENADA* c, int line, int col) {
  c->coluna = col;
  c->linha = line;
}

COORDENADA getJogada1(ESTADO* e, int i) {
  return e->jogadas[i].jogador1;
}

COORDENADA getJogada2(ESTADO* e, int i) {
  return e->jogadas[i].jogador2;
}
