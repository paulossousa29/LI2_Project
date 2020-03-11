#include "headers.h"

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
      switch(e->tab[i][j]) {
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
  for(i = 1;i <= e->num_jogadas;i++) {
    if(i < 10)
      fprintf(ftable, "0%d: ",i);
    else
      fprintf(ftable, "%d: ",i);

    if(i == e->num_jogadas && e->jogador_atual == 2) {
      fprintf(ftable, "%c%d\n",e->ultima_jogada.coluna + 'a',e->ultima_jogada.linha);
    }
    else {
      fprintf(ftable, "%c%d %c%d\n",
      e->jogadas[i-1].jogador1.coluna + 'a',e->jogadas[i-1].jogador1.linha,
      e->jogadas[i-1].jogador2.coluna + 'a',e->jogadas[i-1].jogador2.linha);
    }
  }
  printf("Ficheiro %s gravado\n", name);

  fclose(ftable);
}

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
      e->ultima_jogada.linha = e->jogadas[e->num_jogadas - 1].jogador1.linha;
      e->ultima_jogada.coluna = e->jogadas[e->num_jogadas - 1].jogador1.coluna;

      if(strlen(buffer) > 8) {
        e->jogadas[jogada - 1].jogador2.linha = buffer[8] - '0';
        e->jogadas[jogada - 1].jogador2.coluna = buffer[7] - 'a';
        e->jogador_atual = 1;
        e->ultima_jogada.linha = e->jogadas[e->num_jogadas - 1].jogador2.linha;
        e->ultima_jogada.coluna = e->jogadas[e->num_jogadas - 1].jogador2.coluna;
      }
      else
        e-> jogador_atual = 2;
    }
  }
/*
  if(e->num_jogadas) {
    if(e->jogador_atual == 1) {
      e->ultima_jogada.linha = e->jogadas[e->num_jogadas - 1].jogador2.linha;
      e->ultima_jogada.coluna = e->jogadas[e->num_jogadas - 1].jogador2.coluna;
    }
    else {
      e->ultima_jogada.linha = e->jogadas[e->num_jogadas - 1].jogador1.linha;
      e->ultima_jogada.coluna = e->jogadas[e->num_jogadas - 1].jogador1.coluna;
    }
  }
  */

  fclose(ftable);

  printa(e);
}
