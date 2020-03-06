#include "headers.h"

void output(STATE* e, char* name)
{
  int i, j;
  char aux[MAX]="../files/", c;

  strcat(aux, name);

  FILE* ftable = fopen(aux, "w");

  if(ftable == NULL) {
    printf("Erro\n");
    return;
  }

  for (i=0; i<8; i++) {
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
      fprintf(ftable, "%c", c);
    }
    fprintf(ftable, "%c", '\n');
  }
  printf("Ficheiro %s gravado\n", name);

  fclose(ftable);
}

void input(STATE* e, char* name)
{
  int i, j;
  char buffer[MAX], aux[MAX]="../files/";

  strcat(aux, name);

  FILE* ftable = fopen(aux, "r");

  if(ftable == NULL) {
    printf("Nome de ficheiro inválido\n");
    return;
  }

  for (i=0; fgets(buffer, MAX, ftable); i++)
    for (j=0; buffer[j]; j++)
    {
      if (buffer[j]=='#')
        e->table[i][j]=OCCUPIED;

      else if (buffer[j]=='*')
        e->table[i][j]=CURRENT;

      else if (buffer[j]=='.' || buffer[j]=='1' || buffer[j]=='2')
        e->table[i][j]=EMPTY;
    }

  fclose(ftable);

  printa(e);
}
