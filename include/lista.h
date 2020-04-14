#ifndef __lista_h
#define __lista_h

#include "data.h"

typedef struct lista {
    void* value;
    struct lista* next;
}*LISTA;

LISTA initLista();
LISTA insere_cabeca(LISTA l, void *valor);
LISTA proximo(LISTA l);
LISTA remove_cabeca(LISTA l);
int lista_esta_vazia(LISTA l);

#endif