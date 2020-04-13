#include "data.h"
#include "interface.h"

// Functions
int toCord(COORDENADA* c, char* col, char* line);
void place(ESTADO* e, COORDENADA* c);
void movimentos(ESTADO* e);
void posicao(ESTADO* e, char* pos);
int replay();
int isOver(ESTADO* e);
void winner(ESTADO* e);
COORDENADA Bot(ESTADO *e);
int minmax(CVAL cr,ESTADO e,int isMax,int p);
