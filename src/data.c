#include "data.h"

void gamestart(ESTADO *e)
{
    int i, j;

    for(i=0; i<8; i++)
      for(j=0; j<8; j++)
        e->tab[i][j] = VAZIO;

    e->tab[3][4] = BRANCA;

    e->ultima_jogada.linha = 5;
    e->ultima_jogada.coluna = 4;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
}
