/**
 * @file  files.c
 * @brief Ficheiro que contêm as funções que tratam do input e output de ficheiros 
 */

#include "data.h"
#include "interface.h"

/**
 * @brief       Função que escreve o estado do jogo num ficheiro
 * @param e     Apontador para o Estado
 * @param name  Nome do ficheiro
 */
void output(ESTADO* e, char* name)
{
  int i, j;
  char aux[MAX]="../files/";
  char c = '\0';

  strcat(aux, name);

  FILE* ftable = fopen(aux, "w");

  if(ftable == NULL) {
    printf("Erro\n");
    return;
  }

  for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
      switch(estadoCasa(e, i, j)) {
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

  for(i = 1;i <= numJogadas(e);i++) {
    if(i < 10)
      fprintf(ftable, "0%d: ",i);
    else
      fprintf(ftable, "%d: ",i);

    if(i == numJogadas(e) && jogAtual(e) == 2) {
      fprintf(ftable, "%c%d\n", ultimaJogColuna(e) + 'a',ultimaJogLinha(e));
    }
    else {
      fprintf(ftable, "%c%d %c%d\n",
      getJog1Col(e, i) + 'a',getJog1Line(e, i),
      getJog2Col(e, i) + 'a',getJog2Col(e, i));
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
  char buffer[MAX], aux[MAX]="../files/";

  strcat(aux, name);

  FILE* ftable = fopen(aux, "r");

  if(ftable == NULL) {
    printf("Nome de ficheiro inválido\n");
    return;
  }

  for (i=0; fgets(buffer, MAX, ftable); i++) {
    if(i <= 7) {
      for (j=0; buffer[j]; j++)
      {
        if (buffer[j]=='#')
          e->tab[i][j]=PRETA;

          else if (buffer[j]=='*') {
            e->tab[i][j]=BRANCA;
            e->ultima_jogada.linha = 8 - i;
            e->ultima_jogada.coluna = j;
          }

          else if (buffer[j]=='.' || buffer[j]=='1' || buffer[j]=='2')
          e->tab[i][j]=VAZIO;
        }
    }
    else if (i >= 9) {
      int jogada = 0;

      if(buffer[0] == '0')
        jogada = buffer[1] - '0';
      else
        jogada = (buffer[0] - '0') * 10 + (buffer[1] - '0');

      e->jogadas[jogada - 1].jogador1.linha = buffer[5] - '0';
      e->jogadas[jogada - 1].jogador1.coluna = buffer[4] - 'a';
      e->num_jogadas = jogada;
      e->ultima_jogada.linha = e->jogadas[numJogadas(e) - 1].jogador1.linha;
      e->ultima_jogada.coluna = e->jogadas[numJogadas(e) - 1].jogador1.coluna;

      if(strlen(buffer) > 8) {
        e->jogadas[jogada - 1].jogador2.linha = buffer[8] - '0';
        e->jogadas[jogada - 1].jogador2.coluna = buffer[7] - 'a';
        e->jogador_atual = 1;
        e->ultima_jogada.linha = e->jogadas[numJogadas(e) - 1].jogador2.linha;
        e->ultima_jogada.coluna = e->jogadas[numJogadas(e) - 1].jogador2.coluna;
      }
      else
        e-> jogador_atual = 2;
    }
  }

  fclose(ftable);

  printa(e);
}
