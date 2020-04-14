#ifndef __game_h
#define __game_h

#include "data.h"
#include "lista.h"

// Functions
int toCord(COORDENADA* c, char* col, char* line);
void place(ESTADO* e, LISTA l, COORDENADA* c);
void movimentos(ESTADO* e);
void posicao(ESTADO* e, LISTA l, char* pos);
int isOver(ESTADO* e);

#endif
