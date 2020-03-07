#include "headers.h"

int isValid(STATE* e, int col, int line)
{
  return 1;
}

int fromCL(char col, char line, COORD* c) {
  int i, j;

  printf("%d %d\n", col, line);

  if(col<65 || col>72 || line<49 || line>56)
    return 0;

  for(i = 0, j=72; col!=j; i++, j--);

  c->col = i;
  c->line = line - 49;

  return 1;
}

void place(STATE* e, COORD* c, char* col, char* line)
{
  if(col[1]!='\0' || line[1]!='\0') {
    printf("Argumentos inválidos\n");
    return;
  }

  if(!(fromCL(toupper(col[0]), line[0], c))) {
    printf("A posição não faz parte da grelha\n");
    return;
  }

  if(!(isValid(e, c->col, c->line))) {
    printf("A posição %d %d está ocupada\n", c->col, c->line);
    return;
  }

  e->table[e->curr.line][e->curr.col] = OCCUPIED;
  e->table[c->line][c->col] = CURRENT;
  e->curr.line = c->line;
  e->curr.col = c->col;

  if(e->player == 1) e->player = 2;
  else e->player = 1;

  printa(e);
}
