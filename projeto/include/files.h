/**
 * @file  files.h
 * @brief Ficheiro que contêm as funções que tratam do input e output de ficheiros
 */

#ifndef __files_h
#define __files_h

#include "data.h"
#include "game.h"

/**
 * @brief       Função que escreve o estado do jogo num ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 * @return      Inteiro com resultado de erro
 */
int output(ESTADO* e, char* name);

/**
 * @brief       Função que lê o estado de jogo de um ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 * @return      Inteiro com resultado de erro
 */
LISTA input(ESTADO* e, char* name,LISTA l);

#endif
