/**
 * @file    lista.h
 * @brief   Ficheiro com funções sobre a estrutura Lista
 */

#ifndef __lista_h
#define __lista_h

#include "data.h"

/**
 * @brief Estrutura da Lista Ligada
 */
typedef struct lista {
    void* value;
    struct lista* next;
}*LISTA;

/**
 * @brief   Função que inicia uma Lista
 * @return  Apontador para Lista
 */
LISTA initLista();

/**
 * @brief           Função adiciona valor no início da Lista
 * @param l         Lista à qual se vai adicionar o elemento
 * @param valor     Valor a adicionar
 * @return          Nova lista
 */
LISTA insere_cabeca(LISTA l, void *valor);

/**
 * @brief           Função que devolve a cabeça da lista
 * @param l         Lista
 * @return void*    Apontador para o valor
 */
void *devolve_cabeca(LISTA l);

/**
 * @brief   Função devolve a cauda da Lista
 * @param l Lista com a cauda a devolver
 * @return  Nova Lista com a cauda da Lista l
 */
LISTA proximo(LISTA l);

/**
 * @brief   Remove a cabeça da Lista
 * @param l Lista à qual se vai remover a cabeça
 * @return  Cauda da Lista
 */
LISTA remove_cabeca(LISTA l);

/**
 * @brief   Verifica se uma lista está vazia
 * @param l Lista a verificar
 * @return  Inteiro com resultado booleano
 */
int lista_esta_vazia(LISTA l);

/**
 * @brief       Função que liberta todo o espaço ocupado por uma lista
 * @param l     Lista a libertar
 * @return      Lista vazia
 */
LISTA freeLista(LISTA l);

#endif
