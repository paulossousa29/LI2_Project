/**
 * @file  game.h
 * @brief Ficheiro com funções da lógica do programa
 */

#ifndef __game_h
#define __game_h

#include "data.h"
#include "lista.h"

/**
 * @brief       Função que passa o input do utilizador para uma Coordenada
 * @param c     Apontador para Coordenada
 * @param col   Inteiro com a coluna
 * @param line  Inteiro com a linha
 * @return      Inteiro com resultado booleano
 */
int toCord(COORDENADA* c, char* col, char* line);

/**
 * @brief   Função que efetua uma jogada
 * @param e Apontador para Estado
 * @param l Lista de Estados
 * @param c Apontador para Coordenada
 * @return  Lista de estados
 */
LISTA place(ESTADO* e, LISTA l, COORDENADA* c);

/**
 * @brief     Função que imprime o estado numa determinada posição
 * @param e   Apontador para Estado
 * @param l   Lista de Estados
 * @param pos Jogada a ser apresentada
 * @return      Lista de estados
 */
LISTA posicao(ESTADO* e, LISTA l, int pos);

/**
 * @brief   Função que verifica se o jogo acabou
 * @param e Apontador para Estado
 * @return  Inteiro com resultado booleano
 */
int isOver(ESTADO* e);

#endif
