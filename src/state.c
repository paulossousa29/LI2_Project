#include "headers.h"

void printa(STATE *e)
{
    int i, j, k=104;
    char c = ' ';

    printf("  1 2 3 4 5 6 7 8\n");

    for (i=0; i<8; i++) {
      printf("%c ", k--);

      for (j=0; j<8; j++) {
        switch(e->table[i][j]) {
          case OCCUPIED:
            c = '#';
            break;

          case CURRENT:
            c='*';
            break;

          case EMPTY:
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
    printf("Jogador: %d\n", e->player);
}

void gamestart(STATE *e)
{
    int i, j;

    for(i=0; i<8; i++)
      for(j=0; j<8; j++)
        e->table[i][j] = EMPTY;

    e->table[4][3] = CURRENT;

    e->curr.line = 4;
    e->curr.col = 3;

    e->player = 1;

    printa(e);
}
