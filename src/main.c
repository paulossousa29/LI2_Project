/**
 * @file  main.c
 * @brief Ficheiro que contêm a função main
 */

#include "interface.h"

int main()
{
  ESTADO* e = initEstado();
  COORDENADA* c = initCoordenada();

  execute(e, c);

  free(e);
  free(c);

  return 0;
}
