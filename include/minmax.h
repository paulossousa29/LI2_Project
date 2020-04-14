#include "data.h"
#include "game.h"

typedef struct cval{
    int validas;
    COORDENADA coords[8];
} CVAL;

COORDENADA bot(ESTADO *e);
int minmax(CVAL cr,ESTADO e,int isMax,int p);