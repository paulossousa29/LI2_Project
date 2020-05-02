/**
 * @file  data.h
 * @brief Ficheiro contém funções que tratam dos dados do programa
 */

#ifndef __data_h
#define __data_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 40
#define SMAX 20

/**
 * @brief Tipo de dados para a casa
 */
typedef enum {
    VAZIO,
    BRANCA,
    PRETA
} CASA;

/**
 * @brief Tipo de dados para a Coordenada
 */
typedef struct coordenada{
    int coluna;
    int linha;
}COORDENADA;

/**
 * @brief Tipo de dados para a Jogada
 * 
 */
typedef struct jogada{
    COORDENADA jogador1;
    COORDENADA jogador2;
}JOGADA;

/**
 * @brief Tipo de dados para as Jogadas
 */
typedef JOGADA JOGADAS[32];

/**
 * @brief Tipo de dados para o Estado
 */
typedef struct estado{
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
}ESTADO;


/**
 * @brief   Função que inicia um novo jogo
 * @param e Apontador para Estado
 */
void gamestart(ESTADO *e);

/**
 * @brief   Função que inicializa um Estado
 * @return  Apontador para Estado
 */
ESTADO* initEstado();

/**
 * @brief   Função que inicializa uma Coordenada
 * @return  Apontador para Coordenada
 */
COORDENADA* initCoordenada();

/**
 * @brief   Função que duplica uma Coordenada
 * @param c Apontador para Coordenada
 * @return  Apontador para Coordenada Duplicada
 */
COORDENADA* duplicaCOORD(COORDENADA *c);

/**
 * @brief   Função que duplica um Estado
 * @param e Apontador para Estado
 * @return  Apontador para Estado Duplicado
 */
ESTADO* duplicaEstado(ESTADO* e);

/**
 * @brief   Função que altera o Jogador Atual
 * @param e Apontador para Estado
 */
void setJogAtual(ESTADO *e, int jog);

/**
 * @brief   Função que incrementa o Numero de jogadas
 * @param e Apontador para Estado
 */
void setNJogadas(ESTADO *e,int n);

/**
 * @brief       Função que altera o estado de uma Casa
 * @param e     Apontador para Estado
 * @param a     Novo estado da casa
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setCasa(ESTADO *e, CASA a, int col, int linha);

/**
 * @brief       Função que altera a última jogada
 * @param e     Apontador para Estado
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setUltimaJog(ESTADO *e, int linha, int col);

/**
 * @brief       Função que atualiza adiciona a Jogada do Jogador 1
 * @param e     Apontador para Estado
 * @param i     Inteiro com Jogada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setJog1(ESTADO* e, int i, int line, int col);

/**
 * @brief       Função que atualiza adiciona a Jogada do Jogador 2
 * @param e     Apontador para Estado
 * @param i     Inteiro com Jogada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setJog2(ESTADO* e, int i, int line, int col);

/**
 * @brief       Função atualiza uma coordenada
 * @param c     Apontador para Coordenada
 * @param line  Inteiro com a linha
 * @param col   Inteiro com a coluna
 */
void setCoord(COORDENADA* c, int line, int col);

/**
 * @brief   Função que devolve o Jogador Atual
 * @param e Apontador para Estado
 * @return  Inteiro com o Jogador
 */
int getjogAtual(ESTADO *e);

/**
 * @brief   Função que devolve o Numero de jogadas
 * @param e Apontador para Estado
 * @return  Inteiro com o Numero de jogadas
 */
int getnumJogadas(ESTADO *e);

/**
 * @brief   Devolve a coluna de uma coordenada
 * @param c Apontador para Coordenada
 * @return  Inteiro com a coluna
 */
int getCol(COORDENADA* c);

/**
 * @brief   Devolve a linha de uma coordenada
 * @param c Apontador para Coordenada
 * @return  Inteiro com a linha
 */
int getLine(COORDENADA* c);

/**
 * @brief       Função que devolve o estado de uma Casa
 * @param e     Apontador para Estado
 * @param linha Inteiro com a linha
 * @param col   Inteiro com a coluna
 * @return      Estado da casa
 */
CASA getCasa(ESTADO *e, int col, int linha);

/**
 * @brief   Função que devolve a linha da última jogada
 * @param e Apontador para Estado
 * @return  Inteiro com a linha
 */
int getultimaJogLinha(ESTADO *e);

/**
 * @brief   Função que devolve a coluna da última jogada
 * @param e Apontador para Estado
 * @return  Inteiro com a coluna
 */
int getultimaJogColuna(ESTADO *e);

/**
 * @brief   Devolve a coluna do Jogador 1 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a coluna
 */
int getJog1Col(ESTADO* e, int i);

/**
 * @brief   Devolve a linha do Jogador 1 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a linha
 */
int getJog1Line(ESTADO* e, int i);

/**
 * @brief   Devolve a coluna do Jogador 2 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a coluna
 */
int getJog2Col(ESTADO* e, int i);

/**
 * @brief   Devolve a linha do Jogador 2 numa jogada
 * @param e Apontador para Estado
 * @param i Inteiro com Jogada
 * @return  Inteiro com a linha
 */
int getJog2Line(ESTADO* e, int i);

/**
 * @brief   Função devolve Coordenada de uma jogada do Jogador 1
 * @param e Apontador para Estado
 * @param i Inteiro com a Jogada
 * @return  Coordenada do Jogador 1
 */
COORDENADA getJogada1(ESTADO* e, int i);

/**
 * @brief   Função devolve Coordenada de uma jogada do Jogador 2
 * @param e Apontador para Estado
 * @param i Inteiro com a Jogada
 * @return  Coordenada do Jogador 2
 */
COORDENADA getJogada2(ESTADO* e, int i);

#endif
