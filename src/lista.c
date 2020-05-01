#include "lista.h"

LISTA initLista() {
    return NULL;
}

LISTA insere_cabeca(LISTA l, void *valor) {
    LISTA new = malloc(sizeof(struct lista));

    new->value = valor;
    new->next = l;

    return new;
}

void *devolve_cabeca(LISTA l) {
    return l->value;
}

LISTA proximo(LISTA l) {
    return l->next;
}

LISTA remove_cabeca(LISTA l) {
    LISTA new = l;

    new = new->next;

    free(l);

    return new;
}

int lista_esta_vazia(LISTA l) {
    int res=0;

    if(l == NULL)
        res = 1;

    return res;
}

LISTA freeLista(LISTA l) {
    LISTA aux = l;

    while(aux!=NULL) {
        aux = l->next;
        free(l);
        l = aux;
    }

    return l;
}