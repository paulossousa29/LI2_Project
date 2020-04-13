/**
 * @file    lista.c
 * @brief   Ficheiro com funções sobre a estrutura Lista
 */

#include "lista.h"

struct lista {
    ESTADO* e;
    LISTA* next;
};

/**
 * @brief   Função que inicia uma Lista
 * @return  Apontador para Lista
 */
LISTA* initLista() {
    LISTA* new = malloc(sizeof(LISTA));
    
    new->e = NULL;
    new->next = NULL;

    return new;
}