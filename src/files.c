/**
 * @file  files.c
 * @brief Ficheiro que contêm as funções que tratam do input e output de ficheiros
 */

#include "files.h"


/**
 * @brief       Função que escreve o estado do jogo num ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 */
void output(ESTADO* e, char* name)
{
  int i, j;
  char aux[MAX]="files/";
  char c = '\0';

  strcat(aux, name);

  FILE* ftable = fopen(aux, "w");

  if(ftable == NULL) {
    printf("Erro\n");
    return;
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
    if(i < 10)
      fprintf(ftable, "0%d: ",i);
    else
      fprintf(ftable, "%d: ",i);

    if(i == getnumJogadas(e) && getjogAtual(e) == 2) {
      fprintf(ftable, "%c%d\n", getultimaJogColuna(e) + 'a', '8' - getultimaJogLinha(e));
    }
    else {
      fprintf(ftable, "%c%d %c%d\n",
      getJog1Col(e, i) + 'a', '8' - getJog1Line(e, i),
      getJog2Col(e, i) + 'a', '8' - getJog2Line(e, i));
    }
  }

  printf("Ficheiro %s gravado\n", name);

  fclose(ftable);
}

/**
 * @brief       Função que lê o estado de jogo de um ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 *
 */
void input(ESTADO* e, char* name)
{
  int i, j;
  char buffer[MAX], aux[MAX]="files/";

  strcat(aux, name);

  FILE* ftable = fopen(aux, "r");

  if(ftable == NULL) {
    printf("Nome de ficheiro inválido\n");
    return;
  }

  for (i=0; fgets(buffer, MAX, ftable); i++) {
    if(i <= 7) {
      for (j=0; buffer[j]; j++) {
        if (buffer[j]=='#')
          setCasa(e,PRETA,i,j);

        else if (buffer[j]=='*') {
          setCasa(e,BRANCA,i,j);
          setUltimaJog(e,i,j);
        }

        else if (buffer[j]=='.' || buffer[j]=='1' || buffer[j]=='2')
          setCasa(e,VAZIO,i,j);;
      }
    }
    else if (i >= 9) {
      int jogada = 0;

      if(buffer[0] == '0')
        jogada = buffer[1] - '0';
      else
        jogada = (buffer[0] - '0') * 10 + (buffer[1] - '0');

      setJog1(e,jogada,'8' - buffer[5],buffer[4] - 'a');
      setNJogadas(e,jogada);
      setUltimaJog(e,'8' - buffer[5],buffer[4] - 'a');

      if(strlen(buffer) > 8) {
        setJog2(e,jogada,'8' - buffer[8],buffer[7] - 'a');
        setUltimaJog(e,'8' - buffer[8],buffer[7] - 'a');
        setJogAtual(e,1);
      }
      else
        setJogAtual(e,2);
    }
  }

  fclose(ftable);
}
