/**
 * @file  game.c
 * @brief Ficheiro com funções da lógica do programa
 */

#include "game.h"

/**
 * @brief       Função que passa o input do utilizador para uma Coordenada
 * @param c     Apontador para Coordenada
 * @param col   Inteiro com a coluna
 * @param line  Inteiro com a linha
 * @return      Inteiro com resultado booleano
 */
int toCord(COORDENADA* c, char* col, char* line) {
  if(col[1]!='\0' || line[1]!='\0')
    return 0;


  setCoord(c, '8' - line[0], col[0] - 'a');

  return 1;
}

/**
 * @brief       Função que verifica se uma coordenada é válida
 * @param e     Apontador para Estado
 * @param col   Inteiro com a linha
 * @param line  Inteiro com a coluna
 * @return      Inteiro com resultado booleano
 */
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

/**
 * @brief   Função que efetua uma jogada
 * @param e Apontador para Estado
 * @param l Lista de Estados
 * @param c Apontador para Coordenada
  @return   Lista de estados
 */
LISTA place(ESTADO* e, LISTA l, COORDENADA* c) {
  if(isValid(e, getCol(c), getLine(c))) {
    setCasa(e, PRETA, getultimaJogLinha(e), getultimaJogColuna(e));
    setCasa(e, BRANCA, getLine(c), getCol(c));
    setUltimaJog(e, getLine(c), getCol(c));

    if(getjogAtual(e) == 1) {
      setNJogadas(e,getnumJogadas(e)+1);
      setJog1(e, getnumJogadas(e), getLine(c), getCol(c));
      setJogAtual(e, 2);
      //l = insere_cabeca(l, (void*)duplicaEstado(e));
    }

    else {
      setJog2(e, getnumJogadas(e), getLine(c), getCol(c));
      setJogAtual(e, 1);
      l = insere_cabeca(l, (void*)duplicaEstado(e));
    }

    return l;
  }

  else
    return NULL;

}

/**
 * @brief     Função que imprime o estado numa determinada posição
 * @param e   Apontador para Estado
 * @param l   Lista de Estados
 * @param pos Jogada a ser apresentada
 @return      Lista de estados
 */
LISTA posicao(ESTADO* e, LISTA l, int pos) {
  int jog = getnumJogadas(e);

  if(lista_esta_vazia(l)) return l;

  while(jog>pos && !lista_esta_vazia(proximo(l))) {
    l = remove_cabeca(l);
    jog--;
  }

  return l;
}

/**
 * @brief   Função que verifica se o jogo acabou
 * @param e Apontador para Estado
 * @return  Inteiro com resultado booleano
 */
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
