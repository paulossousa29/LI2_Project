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
int toCord(COORDENADA* c, char* col, char* line)
{
  if(col[1]!='\0' || line[1]!='\0') {
    printf("Argumentos inválidos\n");
    return 0;
  }

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
int isValid(ESTADO* e, int col, int line)
{
  if (col < 0 || col > 7 || line < 0 || line > 7) {
    printf("A posição não faz parte da grelha\n");
    return -1;
  }
  int l = getultimaJogLinha(e);
  int c = getultimaJogColuna(e);

  if(getCasa(e,line, col) == VAZIO) {
    if((l == line && (col == c + 1 || col == c - 1))||
    (c == col && (line == l + 1 || line == l - 1))||
    (line == l + 1 && (col == c - 1 || col == c + 1))||
    (line == l - 1 && (col == c - 1 || col == c + 1)))
      return 0;

    else {
      printf("A posição %c %d não é adjacente %c %d\n", col + 'a', 8 - line,c+'a',l);
    }
  }

  else
    printf("A posição %c %d é inválida\n", col + 'a', 8 - line);

  return -1;
}

/**
 * @brief   Função que efetua uma jogada
 * @param e Apontador para Estado
 * @param l Lista de Estados
 * @param c Apontador para Coordenada
 */
void place(ESTADO* e, LISTA l, COORDENADA* c)
{
  if(!(isValid(e, getCol(c), getLine(c)))) {
    setCasa(e, PRETA, getultimaJogLinha(e), getultimaJogColuna(e));
    setCasa(e, BRANCA, getLine(c), getCol(c));
    setUltimaJog(e, getLine(c), getCol(c));

    if(getjogAtual(e) == 1) {
      setNJogadas(e,getnumJogadas(e)+1);
      setJog1(e, getnumJogadas(e)-1, getLine(c), getCol(c));
      setJogAtual(e, 2);
    }

    else {
      setJog2(e, getnumJogadas(e)-1, getLine(c), getCol(c));
      l = insere_cabeca(l, duplicaEstado(e));
      setJogAtual(e, 1);
    }
  }
}

/**
 * @brief   Função que imprime a Lista de Movimentos
 * @param e Apontador para Estado
 */
void movimentos(ESTADO* e) {
  int i;

  printf("\nMovimentos:\n");

  if(getnumJogadas(e) == 0)
    printf("Não existem jogadas\n");

  for(i=1; i<=getnumJogadas(e); i++) {

    printf("%2d: ",i);

    if(i == getnumJogadas(e) && getjogAtual(e) == 2) {
      printf("%c%d\n",getultimaJogColuna(e) + 'a', '8' - getultimaJogLinha(e));
    }

    else {
      printf("%c%d %c%d\n",
      getJog1Col(e, i) + 'a', '8' - getJog1Line(e, i),
      getJog2Col(e, i) + 'a', '8' - getJog2Line(e, i));
    }
  }
}

/**
 * @brief     Função que imprime o estado numa determinada posição
 * @param e   Apontador para Estado
 * @param l   Lista de Estados
 * @param pos Jogada a ser apresentada
 */
ESTADO* posicao(ESTADO* e, LISTA l, int pos) {
  int jog = getnumJogadas(e);
  LISTA aux = l;

  while(jog>pos && aux) {
    aux = aux->next;
    jog--;
  }

  return aux->value;
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
      if(c2 >= 0 && c2<8 && getCasa(e, l2, c2) == VAZIO) {
        return 0;
      }

  if(getjogAtual(e) == 1)
    return 2;

  return 1;
}
