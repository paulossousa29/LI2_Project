/**
 * @file  data.c
 * @brief Ficheiro contém funções que tratam dos dados do programa 
 */

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

/**
 * @brief   Função que inicia um novo jogo
 * @param e Apontador para Estado
 */
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

/**
 * @brief   Função que inicializa um Estado
 * @return  Apontador para Estado
 */
ESTADO* initEstado() {
  ESTADO* new = malloc(sizeof(ESTADO));

  return new;
}

/**
 * @brief   Função que inicializa uma Coordenada
 * @return  Apontador para Coordenada
 */
COORDENADA* initCoordenada() {
  COORDENADA* new = malloc(sizeof(COORDENADA));

  return new;
}

/**
 * @brief   Função que devolve o Jogador Atual
 * @param e Apontador para Estado
 * @return  Inteiro com o Jogador
 */
int jogAtual(ESTADO *e) {
  return e->jogador_atual;
}

/**
 * @brief   Função que altera o Jogador Atual
 * @param e Apontador para Estado
 */
void alteraJog(ESTADO *e, int jog) {
  e->jogador_atual = jog;
}

/**
 * @brief   Função que devolve o Numero de jogadas
 * @param e Apontador para Estado
 * @return  Inteiro com o Numero de jogadas
 */
int numJogadas(ESTADO *e) {
  return e->num_jogadas;
}

/**
 * @brief   Função que incrementa o Numero de jogadas
 * @param e Apontador para Estado
 */
void incJogadas(ESTADO *e) {
  e->num_jogadas++;
}

/**
 * @brief       Função que devolve o estado de uma Casa
 * @param e     Apontador para Estado
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 * @return      Estado da casa
 */
CASA estadoCasa(ESTADO *e, int linha, int col) {
  return e->tab[linha][col];
}

/**
 * @brief       Função que altera o estado de uma Casa
 * @param e     Apontador para Estado
 * @param a     Novo estado da casa
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void alteraCasa(ESTADO *e, CASA a, int linha, int col) {
  e->tab[linha][col] = a;
}

/**
 * @brief   Função que devolve a linha da última jogada
 * @param e Apontador para Estado
 * @return  Inteiro com a linha
 */
int ultimaJogLinha(ESTADO *e) {
  return e->ultima_jogada.linha;
}

/**
 * @brief   Função que devolve a coluna da última jogada
 * @param e Apontador para Estado
 * @return  Inteiro com a coluna
 */
int ultimaJogColuna(ESTADO *e) {
  return e->ultima_jogada.coluna;
}

/**
 * @brief       Função que altera a última jogada
 * @param e     Apontador para Estado
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void alteraUltimaJog(ESTADO *e, int linha, int col) {
  e->ultima_jogada.linha = linha;
  e->ultima_jogada.coluna = col;
}

/**
 * @brief   Devolve a coluna do Jogador 1 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a coluna
 */
int getJog1Col(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador1.coluna;
}

/**
 * @brief   Devolve a linha do Jogador 1 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a linha
 */
int getJog1Line(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador1.linha;
}

/**
 * @brief   Devolve a coluna do Jogador 2 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a coluna
 */
int getJog2Col(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador2.coluna;
}

/**
 * @brief   Devolve a linha do Jogador 2 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a linha
 */
int getJog2Line(ESTADO* e, int i) {
  return e->jogadas[i-1].jogador2.linha;
}

/**
 * @brief       Função que atualiza adiciona a Jogada do Jogador 1
 * @param e     Apontador para Estado 
 * @param i     Inteiro com Jogada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setJog1(ESTADO* e, int i, int line, int col) {
  e->jogadas[i-1].jogador1.linha = line;
  e->jogadas[i-1].jogador1.coluna = col;
}

/**
 * @brief       Função que atualiza adiciona a Jogada do Jogador 2
 * @param e     Apontador para Estado 
 * @param i     Inteiro com Jogada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setJog2(ESTADO* e, int i, int line, int col) {
  e->jogadas[i-1].jogador2.linha = line;
  e->jogadas[i-1].jogador2.coluna = col;
}

/**
 * @brief   Devolve a coluna de uma coordenada
 * @param c Apontador para Coordenada
 * @return  Inteiro com a coluna
 */
int getCol(COORDENADA* c) {
  return c->coluna;
}

/**
 * @brief   Devolve a linha de uma coordenada
 * @param c Apontador para Coordenada
 * @return  Inteiro com a linha
 */
int getLine(COORDENADA* c) {
  return c->linha;
}

/**
 * @brief       Função atualiza uma coordenada
 * @param c     Apontador para Coordenada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setCoord(COORDENADA* c, int line, int col) {
  c->coluna = col;
  c->linha = line;
}

/**
 * @brief     Devolve o numero de validas
 * @param cr  Apontador para CVAL
 * @return    Inteiro com o numero de validas
 */
int getValidas(CVAL* cr) {
  return cr->validas;
}

/**
 * @brief     Função que devolve uma Coordenada da estrutura CVAL
 * @param cr  Apontador para CVAL
 * @param i   Posição da coordenada no array
 * @return    Coordenada
 */
COORDENADA getCoord(CVAL* cr, int i) {
  return cr->coords[i];
}

/**
 * @brief   Função devolve Coordenada de uma jogada do Jogador 1
 * @param e Apontador para Estado
 * @param i Inteiro com a Jogada
 * @return  Coordenada do Jogador 1
 */
COORDENADA getJogada1(ESTADO* e, int i) {
  return e->jogadas[i].jogador1;
}

/**
 * @brief   Função devolve Coordenada de uma jogada do Jogador 2
 * @param e Apontador para Estado
 * @param i Inteiro com a Jogada
 * @return  Coordenada do Jogador 2
 */
COORDENADA getJogada2(ESTADO* e, int i) {
  return e->jogadas[i].jogador2;
}