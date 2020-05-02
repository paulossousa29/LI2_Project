/**
 * @file  interface.h
 * @brief Ficheiro com funções que devolvem resultados visuais para o utilizador
 */

#ifndef __interface_h
#define __interface_h

#include "data.h"
#include "lista.h"
#include "files.h"
#include "game.h"
#include "bot.h"

/**
 * @brief   Função que executa o interpretador de comandos
 * @param e Apontador para Estado
 * @param c Apontador para Coordenada
 */
void execute(ESTADO* e, LISTA l, COORDENADA* c);

#endif
