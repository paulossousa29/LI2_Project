#ifndef __game_h
#define __game_h

#include "data.h"
#include "lista.h"

// Functions
int toCord(COORDENADA* c, char* col, char* line);
LISTA place(ESTADO* e, LISTA l, COORDENADA* c);
LISTA posicao(ESTADO* e, LISTA l, int pos);
int isOver(ESTADO* e);

#endif
