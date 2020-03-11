#include "data.h"
#include "interface.h"

int main()
{
  ESTADO* e = malloc(sizeof(ESTADO));
  COORDENADA* c = malloc(sizeof(COORDENADA));

  gamestart(e);

  execute(e, c);

  return 0;
}
