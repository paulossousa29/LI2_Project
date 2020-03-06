#include "headers.h"

int main()
{
  char buffer[MAX];
  STATE* e = malloc(sizeof(STATE));

  while(toupper(buffer[0])!='Q')
  {
    menu();
    fgets(buffer, MAX, stdin);
    printf("\n");
    execute(buffer, e);
  }

  return 0;
}
