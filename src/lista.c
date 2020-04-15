/**
 * @file    lista.c
 * @brief   Ficheiro com funções sobre a estrutura Lista
 */

#include "lista.h"

/**
 * @brief   Função que inicia uma Lista
 * @return  Apontador para Lista
 */
LISTA initLista() {
    LISTA new = malloc(sizeof(LISTA));

    new->value = NULL;
    new->next = NULL;

    return new;
}

/**
 * @brief           Função adiciona valor no início da Lista
 * @param l         Lista à qual se vai adicionar o elemento
 * @param valor     Valor a adicionar
 * @return          Nova lista
 */
LISTA insere_cabeca(LISTA l, void *valor) {
    LISTA new = malloc(sizeof(struct lista));

    new->value = valor;
    new->next = l;

    return new;
}

void *devolve_cabeca(LISTA l) {
  //printf("%d\n", ((COORDENADA*)l->value)->linha);

    return l->value;
}

/**
 * @brief   Função devolve a cauda da Lista
 * @param l Lista com a cauda a devolver
 * @return  Nova Lista com a cauda da Lista l
 */
LISTA proximo(LISTA l) {
    return l->next;
}

/**
 * @brief   Remove a cabeça da Lista
 * @param l Lista à qual se vai remover a cabeça
 * @return  Cauda da Lista
 */
LISTA remove_cabeca(LISTA l) {
    LISTA new = l;

    new = new->next;

    free(l);

    return new;
}

/**
 * @brief   Verifica se uma lista está vazia
 * @param l Lista a verificar
 * @return  Inteiro com resultado booleano
 */
int lista_esta_vazia(LISTA l) {
    int res=0;

    if(l == NULL)
        res = 1;

    return res;
}
