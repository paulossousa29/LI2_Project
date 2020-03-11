#include "headers.h"

int main()
{
  char buffer[MAX];
  ESTADO* e = malloc(sizeof(ESTADO));
  COORDENADA* c = malloc(sizeof(COORDENADA));

  gamestart(e);

  while(toupper(buffer[0])!='Q')
  {
    menu();
    fgets(buffer, MAX, stdin);
    printf("\n");
    execute(buffer, e, c);
  }

  return 0;
}
