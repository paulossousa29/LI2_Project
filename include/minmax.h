#include "data.h"
#include "game.h"
#include "math.h"


typedef struct cval{
    int validas;
    COORDENADA coords[8];
} CVAL;

COORDENADA bot(ESTADO *e);
COORDENADA bot2(ESTADO *e);
