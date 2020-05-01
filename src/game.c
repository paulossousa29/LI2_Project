#include "game.h"

int toCord(COORDENADA* c, char* col, char* line) {
  if(col[1]!='\0' || line[1]!='\0')
    return 0;


  setCoord(c, '8' - line[0], col[0] - 'a');

  return 1;
}

int isValid(ESTADO* e, int col, int line) {
  if (col < 0 || col > 7 || line < 0 || line > 7)
    return 0;

  int l = getultimaJogLinha(e);
  int c = getultimaJogColuna(e);

  if(getCasa(e,line, col) == VAZIO) {
    if((l == line && (col == c + 1 || col == c - 1))||
    (c == col && (line == l + 1 || line == l - 1))||
    (line == l + 1 && (col == c - 1 || col == c + 1))||
    (line == l - 1 && (col == c - 1 || col == c + 1)))
      return 1;
  }

  return 0;
}

LISTA place(ESTADO* e, LISTA l, COORDENADA* c) {
  if(isValid(e, getCol(c), getLine(c))) {
    setCasa(e, PRETA, getultimaJogLinha(e), getultimaJogColuna(e));
    setCasa(e, BRANCA, getLine(c), getCol(c));
    setUltimaJog(e, getLine(c), getCol(c));

    if(getjogAtual(e) == 1) {
      setNJogadas(e,getnumJogadas(e)+1);
      setJog1(e, getnumJogadas(e), getLine(c), getCol(c));
      setJogAtual(e, 2);
      l = insere_cabeca(l, (void*)duplicaEstado(e));
    }

    else {
      setJog2(e, getnumJogadas(e), getLine(c), getCol(c));
      if(!lista_esta_vazia(l))
        l = remove_cabeca(l);
      l = insere_cabeca(l, (void*)duplicaEstado(e));
      setJogAtual(e, 1);
    }

    return l;
  }

  else
    return NULL;

}

LISTA posicao(ESTADO* e, LISTA l, int pos) {
  int jog = getnumJogadas(e);

  while(jog>pos && !lista_esta_vazia(l->next)) {
    l = remove_cabeca(l);
    jog--;
  }

  return l;
}

int isOver(ESTADO* e) {
  int c = getultimaJogColuna(e);
  int l = getultimaJogLinha(e);
  int l2 = l - 1, c2;

  if (getCasa(e, 7, 0) == BRANCA)
    return 1;

  else if (getCasa(e, 0, 7) == BRANCA)
    return 2;

  if(l==0)
    l2++;

  for(;l2<=l+1 && l2<8; l2++)
    for(c2 = c-1; c2<=c+1; c2++)
      if(c2 >= 0 && c2<8 && getCasa(e, l2, c2) == VAZIO)
        return 0;

  if(getjogAtual(e) == 1)
    return 2;

  return 1;
}
