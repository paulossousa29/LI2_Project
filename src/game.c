#include "data.h"
#include "interface.h"

int isValid(ESTADO* e, int col, int line)
{
  if (col < 0 || col > 7 || line < 1 || line > 8) {
    printf("A posição não faz parte da grelha\n");
    return -1;
  }
  int l = e->ultima_jogada.linha;
  int c = e->ultima_jogada.coluna;

  if(e->tab[8 - line][col] == VAZIO) {
    if((l == line && (col == c + 1 || col == c - 1))||
    (c == col && (line == l + 1 || line == l - 1))||
    (line == l + 1 && (col == c - 1 || col == c + 1))||
    (line == l - 1 && (col == c - 1 || col == c + 1)))
      return 0;
    else {
      printf("A posição %c %d não é adjacente %c %d\n", col + 'a',line,c+'a',l);
    }
  }
  else
    printf("A posição %c %d é inválida\n", col + 'a',line);

  return -1;
}

void place(ESTADO* e, COORDENADA* c, char* col, char* line)
{
  if(col[1]!='\0' || line[1]!='\0') {
    printf("Argumentos inválidos\n");
    return;
  }

  c -> coluna = col[0] - 'a';
  c -> linha = line[0] - '0';

  if(!(isValid(e, c->coluna, c->linha))) {

    e->tab[8 - e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
    e->tab[8 - c->linha][c->coluna] = BRANCA;
    e->ultima_jogada.linha = c->linha;
    e->ultima_jogada.coluna = c->coluna;

    if(e->jogador_atual == 1) {
      e->jogador_atual = 2;
      e->num_jogadas++;
      e->jogadas[e->num_jogadas-1].jogador1.linha = c -> linha;
      e->jogadas[e->num_jogadas-1].jogador1.coluna = c -> coluna;
    }

    else {
      e->jogador_atual = 1;
      e->jogadas[e->num_jogadas-1].jogador2.linha = c -> linha;
      e->jogadas[e->num_jogadas-1].jogador2.coluna = c -> coluna;
    }

  printa(e);
  }
}

int isOver(ESTADO* e)
{
  int c = e->ultima_jogada.coluna;
  int l = e->ultima_jogada.linha;
  if (e->tab[7][0] == BRANCA) {
    e->jogador_atual = 1;
    return 1;
  }
  else if (e->tab[0][7] == BRANCA) {
    e->jogador_atual = 2;
    return 1;
  }
  else if (l == 8 && c == 0) {
    if (e->tab[1][c+1] == PRETA && e->tab[1][c] == PRETA && e->tab[0][c+1] == PRETA)
      return 1;
  }

  else if (l==1 && c ==7) {
    if (e->tab[6][c-1] == PRETA && e->tab[6][c] == PRETA && e->tab[7][c-1] == PRETA)
      return 1;
  }

  else if (l == 8) {
    if ((e->tab[0][c+1] == PRETA || c+1 == 7) && e->tab[0][c-1] == PRETA
    && e->tab[1][c+1] == PRETA
    && e->tab[1][c] == PRETA && e->tab[1][c-1] == PRETA)
      return 1;
  }

  else if (l == 1) {
    if (e->tab[7][c+1] == PRETA && (e->tab[7][c-1] == PRETA || c-1 == 0)
    && e->tab[6][c+1] == PRETA
    && e->tab[6][c] == PRETA && e->tab[6][c-1] == PRETA)
      return 1;
  }

  else if (c == 0) {
    if (e->tab[8-l-1][c] == PRETA && (e->tab[8-l+1][c] == PRETA || 8-l+1 == 7)
    && e->tab[8-l-1][c+1] == PRETA
    && e->tab[8-l][c+1] == PRETA && e->tab[8-l+1][c+1] == PRETA)
      return 1;
  }

  else if (c == 7) {
    if (e->tab[8-l+1][c] == PRETA && (e->tab[8-l-1][c] == PRETA || ((8-l-1) == 0))
    && e->tab[8-l-1][c-1] == PRETA
    && e->tab[8-l][c-1] == PRETA && e->tab[8-l+1][c-1] == PRETA)
      return 1;
  }

  else if
    ((e->tab[8-l-1][c] == PRETA
    && (e->tab[8-l-1][c+1] == PRETA || (8-l-1 == 0 && c+1 == 7))
    && e->tab[8-l][c+1] == PRETA
    && e->tab[8-l-1][c] == PRETA
    && e->tab[8-l+1][c+1] == PRETA
    && e->tab[8-l+1][c] == PRETA
    && (e->tab[8-l+1][c-1] == PRETA || (8-l+1 == 7 && c-1 == 0))
    && e->tab[8-l][c-1] == PRETA
    && e->tab[8-l-1][c-1] == PRETA))
      return 1;

  return 0;
}
