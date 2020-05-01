/**
 * @file    bot.h
 * @brief   Módulo que contém a implementação das funções para os BOTs
 */

#ifndef __bot_h
#define __bot_h

#include "data.h"
#include "game.h"
#include "math.h"

/**
 * @brief       Funçao que implementa a estratégia fácil do bot
 * @param e     Apontador para o estado
 * @return      Coordenada onde o bot deve jogar
 */
COORDENADA bot(ESTADO *e);

/**
 * @brief       Funçao que implementa a estratégia dificil do bot
 * @param e     Apontador para o estado
 * @return      Coordenada onde o bot deve jogar
 */
COORDENADA bot2(ESTADO *e);

#endif