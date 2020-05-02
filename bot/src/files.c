/**
 * @file  files.h
 * @brief Ficheiro que contêm as funções que tratam do input e output de ficheiros
 */
#include "files.h"

/**
 * @brief       Função que escreve o estado do jogo num ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 * @return      Inteiro com resultado de erro
 */
int output(ESTADO* e, char* name)
{
  int i, j;
  char aux[MAX]="files/";
  char c = '\0';

  strcat(aux, name);

  FILE* ftable = fopen(aux, "w");

  if(ftable == NULL) {
    return -1;
  }

  for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
      switch(getCasa(e,i, j)) {
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
      fprintf(ftable, "%c", c);
    }
    fprintf(ftable, "%c", '\n');
  }
  //lista de movimentos
  fprintf(ftable, " \n");

  for(i = 1;i <= getnumJogadas(e);i++) {
      fprintf(ftable, "%02d: ",i);

    if(i == getnumJogadas(e) && getjogAtual(e) == 2)
      fprintf(ftable, "%c%d\n", getultimaJogColuna(e) + 'a', 8 - getultimaJogLinha(e));
    else {
      fprintf(ftable, "%c%d %c%d\n",
      getJog1Col(e, i) + 'a', 8 - getJog1Line(e, i),
      getJog2Col(e, i) + 'a', 8 - getJog2Line(e, i));
    }
  }

  fclose(ftable);

  return 0;
}

/**
 * @brief       Função que lê o estado de jogo de um ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 * @param l     Lista de estados
 * @return      Lista de estados
 */
LISTA input(ESTADO* e, char* name,LISTA l)
{
  int i;
  char buffer[MAX], aux[MAX]="files/";
  COORDENADA *cr = initCoordenada();

  strcat(aux, name);

  FILE* ftable = fopen(aux, "r");

  if(ftable == NULL)
    return NULL;

  gamestart(e);
  l = freeLista(l);
  l = insere_cabeca(l,(void*)duplicaEstado(e));


  for (i=0; fgets(buffer, MAX, ftable); i++) {
    if (i >= 9 && strlen(buffer) > 3) {
      cr -> linha = '8' - buffer[5];
      cr -> coluna = buffer[4] - 'a';

      l = place(e,l,cr);

      if(strlen(buffer) > 8) {
        cr -> linha = '8' - buffer[8];
        cr -> coluna = buffer[7] - 'a';

        l = place(e,l,cr);
      }
    }
  }

  fclose(ftable);

  return l;
}
