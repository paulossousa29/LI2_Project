#include "headers.h"

int main()
{
  char buffer[MAX];
  STATE* e = malloc(sizeof(STATE));
  COORD* c = malloc(sizeof(COORD));

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
