#include "headers.h"

void printa(ESTADO *e)
{
    int i, j, k=104;
    char c = ' ';

    printf("  a b c d e f g h\n");

    for (i=0; i<8; i++) {
      printf("%d ", 8-i);

      for (j=0; j<8; j++) {
        switch(e->tab[i][j]) {
          case PRETA:
            c = '#';
            break;

          case BRANCA:
            c='*';
            break;

          case VAZIO:
            if(i == 7 && j == 0) c = '1';
            else if  (i == 0 && j == 7) c = '2';
            else c = '.';
            break;

          default:
            break;
        }
        printf("%c ", c);
      }
      printf("\n");
    }
    printf("Jogador: %d\n", e->jogador_atual);
}

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

    printa(e);
}
