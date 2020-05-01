/**
 * @file  main.c
 * @brief Ficheiro que contêm a função main do jogo
 */

#include "interface.h"

/**
 * @brief   Função main do jogo
 * @return  Inteiro com resultado de erro
 */
int main()
{
  ESTADO* e = initEstado();
  COORDENADA* c = initCoordenada();
  LISTA l = initLista();

  execute(e, l, c);

  free(e);
  free(c);
  free(l);

  return 0;
}
