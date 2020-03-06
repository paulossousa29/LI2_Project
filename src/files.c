#include "headers.h"

void input(STATE* e, char* name)
{
  int i, j, k;
  char buffer[MAX], aux[MAX]="../files/";

  strcat(aux, name);

  FILE* ftable = fopen(aux, "r");

  for (i = 1; fgets(buffer, MAX, ftable); i++)
  {
    k=0;

    for (j=0; buffer[j]; j++)
    {
      if (buffer[j]=='#')
      {
        e->table[i-2][k]=OCCUPIED;
        k++;
      }

      else if (buffer[j]=='*')
      {
        e->table[i-2][k]=CURRENT;
        k++;
      }

      else if (buffer[j]=='.' || buffer[j]=='1' || buffer[j]=='2')
      {
        e->table[i-2][k]=EMPTY;
        k++;
      }
    }
  }

  printa(e);

  fclose(ftable);
}
