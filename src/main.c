/**
 * @file  main.c
 * @brief Ficheiro que contêm a função main
 */

#include "interface.h"

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
