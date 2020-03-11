#include "headers.h"

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

/*
int fromCL(char col, char line, COORDENADA* c) {
  int i, j;

  printf("%d %d\n", col, line);

  if(col<65 || col>72 || line<49 || line>56)
    return 0;

  for(i = 0, j=72; col!=j; i++, j--);

  c->coluna = i;
  c->linha = line - 49;

  return 1;
}
*/
int isOver(ESTADO* e){
  int c = e->ultima_jogada.coluna;
  int l = e->ultima_jogada.linha;
  if (e->tab[7][0] == BRANCA) return 1;

  else if (e->tab[0][7] == BRANCA) return 1;

  else if (l == 0 && c == 0) {
    if (e->tab[l+1][c+1] == PRETA && e->tab[l+1][c] == PRETA && e->tab[l][c+1] == PRETA)
      return 1;
  }

  else if (l==7 && c ==7) {
    if (e->tab[l-1][c-1] == PRETA && e->tab[l-1][c] == PRETA && e->tab[l][c-1] == PRETA)
      return 1;
  }

  else if (l == 0) {
    if ((e->tab[l][c+1] == PRETA || c+1 == 7) && e->tab[l][c-1] == PRETA
    && e->tab[l+1][c+1] == PRETA
    && e->tab[l+1][c] == PRETA && e->tab[l+1][c-1] == PRETA)
      return 1;
  }

  else if (l == 7) {
    if (e->tab[l][c+1] == PRETA && (e->tab[l][c-1] == PRETA || c-1 == 0)
    && e->tab[l-1][c+1] == PRETA
    && e->tab[l-1][c] == PRETA && e->tab[l-1][c-1] == PRETA)
      return 1;
  }

  else if (c == 0) {
    if (e->tab[l-1][c] == PRETA && (e->tab[l+1][c] == PRETA || l+1 == 7)
    && e->tab[l-1][c+1] == PRETA
    && e->tab[l][c+1] == PRETA && e->tab[l+1][c+1] == PRETA)
      return 1;
  }

  else if (c == 7) {
    if (e->tab[l+1][c] == PRETA && (e->tab[l-1][c] == PRETA || ((l-1) == 0))
    && e->tab[l-1][c-1] == PRETA
    && e->tab[l][c-1] == PRETA && e->tab[l+1][c-1] == PRETA)
      return 1;
  }

  else if
    ((e->tab[l-1][c] == PRETA
    && (e->tab[l-1][c+1] == PRETA || (l-1 == 0 && c+1 == 7))
    && e->tab[l][c+1] == PRETA
    && e->tab[l-1][c] == PRETA
    && e->tab[l+1][c+1] == PRETA
    && e->tab[l+1][c] == PRETA
    && (e->tab[l+1][c-1] == PRETA || (l+1 == 7 && c-1 == 0))
    && e->tab[l][c-1] == PRETA
    && e->tab[l-1][c-1] == PRETA))
      return 1;

  return 0;
}

void place(ESTADO* e, COORDENADA* c, char* col, char* line)
{
  if(col[1]!='\0' || line[1]!='\0') {
    printf("Argumentos inválidos\n");
    return;
  }
/*
  if(!(fromCL(toupper(col[0]), line[0], c))) {
    printf("A posição não faz parte da grelha\n");
    return;
  }
*/
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
