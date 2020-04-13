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

  c->coluna = col[0] - 'a';
  c->linha = line[0] - '0';

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
  if (col < 0 || col > 7 || line < 1 || line > 8) {
    printf("A posição não faz parte da grelha\n");
    return -1;
  }
  int l = ultimaJogLinha(e);
  int c = ultimaJogColuna(e);

  if(estadoCasa(e, 8-line, col) == VAZIO) {
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

/**
 * @brief   Função que efetua uma jogada
 * @param e Apontador para Estado
 * @param c Apontador para Coordenada
 */
void place(ESTADO* e, COORDENADA* c)
{
  if(!(isValid(e, getCol(c), getLine(c)))) {
    alteraCasa(e, PRETA, 8 - ultimaJogLinha(e), ultimaJogColuna(e));
    alteraCasa(e, BRANCA, 8 - getLine(c), getCol(c));
    alteraUltimaJog(e, getLine(c), getCol(c));

    if(jogAtual(e) == 1) {
      alteraJog(e, 2);
      incJogadas(e);
      e->jogadas[numJogadas(e)-1].jogador1.linha = getLine(c);
      e->jogadas[numJogadas(e)-1].jogador1.coluna = getCol(c);
    }

    else {
      alteraJog(e, 1);
      e->jogadas[numJogadas(e)-1].jogador2.linha = getLine(c);
      e->jogadas[numJogadas(e)-1].jogador2.coluna = getCol(c);
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

  if(numJogadas(e) == 0)
    printf("Não existem jogadas\n");

  for(i=1; i<=numJogadas(e); i++) {

    if(i < 10)
      printf("0%d: ",i);

    else
      printf("%d: ",i);

    if(i == numJogadas(e) && jogAtual(e) == 2) {
      printf("%c%d\n",ultimaJogColuna(e) + 'a', ultimaJogLinha(e));
    }

    else {
      printf("%c%d %c%d\n",
      getJog1Col(e, i) + 'a',getJog1Line(e, i),
      getJog2Col(e, i) + 'a',getJog2Line(e, i));
    }
  }
}

/**
 * @brief     Função que imprime o estado numa determinada posição
 * @param e   Apontador para Estado
 * @param pos Jogada a ser apresentada
 */
void posicao(ESTADO* e, char* pos) {
  int i, jog;
  ESTADO* aux = initEstado();

  gamestart(aux);

  if((jog = atoi(pos)) == 0)
    printf("Argumento inválido\n");

  if(jog >= numJogadas(e))
    printf("A jogada %d não existe\n", jog);

  for(i=0; i<jog; i++)
  {
    place(aux, &(e->jogadas[i].jogador1));
    place(aux, &(e->jogadas[i].jogador2));
  }

  printa(aux);
}

/**
 * @brief   Função que verifica se o jogo acabou
 * @param e Apontador para Estado
 * @return  Inteiro com resultado booleano
 */
int isOver(ESTADO* e) {
  int c = ultimaJogColuna(e);
  int l = ultimaJogLinha(e);
  int l2 = l;

  if (estadoCasa(e, 7, 0) == BRANCA)
    return 1;

  else if (estadoCasa(e, 0, 7) == BRANCA)
    return 2;

  if(l2 == 1) l2++;

  for(l2 = l - 1;l2 <= l + 1 && l2 < 9;l2++) {
    for(int c2 = c - 1;c2 <= c + 1;c2++)
      if(c2 >= 0 && c2 <=7 && estadoCasa(e, 8-l2, c2) == VAZIO)
        return 0;
  }

  if(jogAtual(e) == 1)
    return 2;

  return 1;
}

// Funções para seleção da melhor jogada (BOT)

CVAL jogadasValidas(ESTADO *e) {
  CVAL cr;
  int l = ultimaJogLinha(e);
  int c = ultimaJogColuna(e);
  int i = 0, l2 = l;

  if(l2 == 1) l2++;

  for(l2 = l - 1;l2 <= l + 1 && l2 < 9;l2++) {
    for(int c2 = c - 1;c2 <= c + 1;c2++)
      if(c2 >= 0 && c2 <=7 && estadoCasa(e, 8-l2, c2) == VAZIO) {
        cr.coords[i].linha = l2;
        cr.coords[i].coluna = c2;
        i++;
      }
  }
  cr.validas = i;
  return cr;
}

ESTADO jogadaBot(ESTADO e,COORDENADA *c) {
  e.tab[8 - ultimaJogLinha(&e)][ultimaJogColuna(&e)] = PRETA;
  e.tab[8 - getLine(c)][getCol(c)] = BRANCA;
  alteraUltimaJog(&e, getLine(c), getCol(c));

  if(jogAtual(&e) == 1)
    alteraJog(&e, 1);
  else
    alteraJog(&e, 2);

  return e;
}

int pertoFim(COORDENADA c,int jogador) {
  if(((getLine(&c) == 8 && getCol(&c) == 6) || (getLine(&c) == 7 && getCol(&c) == 6) ||
    (getLine(&c) == 7 && getCol(&c) == 7)) && jogador == 1)
    return 1;

  if(((getLine(&c) == 2 && getCol(&c) == 0) || (getLine(&c) == 2 && getCol(&c) == 1) ||
    (getLine(&c) == 1 && getCol(&c) == 1)) && jogador == 2)
    return 1;

  return 0;
}

int avaliaJogada(ESTADO e,COORDENADA c) {
  int j = jogAtual(&e),p;
  ESTADO a = jogadaBot(e,&c);
  int l = ultimaJogLinha(&e),cl = ultimaJogColuna(&e);

  p = isOver(&a);
  if(p != j && p)
    p = 1;
  else if(p == j)
          p = 8;
  else if((pertoFim(c,j)))
          p = 2;
  else if((j == 2 && getLine(&c) == l + 1 && getCol(&c) == cl + 1) ||
          (j == 1 && getLine(&c) == l - 1 && getCol(&c) == cl - 1))
          p = 7;
  else if((l == getLine(&c)) && ((j == 2 && getCol(&c) == cl + 1) ||
          (j == 1 && getCol(&c) == cl - 1)))
          p = 5;
  else if((cl == getCol(&c)) && ((j == 2 && getLine(&c) == l + 1) ||
          (j == 1 && getLine(&c) == l - 1)))
          p = 6;
  else if((getLine(&c) == l + 1 && getCol(&c) == cl - 1) ||
          (getLine(&c) == l - 1 && getCol(&c) == cl + 1))
          p = 4;
  else p = 3;

  return p;
}

int minmax(CVAL cr,ESTADO e,int isMax,int p) {
  int pontos,max,min;
  ESTADO a;

  if (isMax) {
    max = -100;
    for(int i = 0;i < getValidas(&cr);i++) {
      a = jogadaBot(e, &cr.coords[i]);
      if(!p || isOver(&a))
        pontos = avaliaJogada(e,  cr.coords[i]);
      else
        pontos = minmax(jogadasValidas(&a),a,0,p-1);

      if(pontos > max)
        max = pontos;
      //printf("-%d%c%d \n", pontos,'a' + cr.coords[i].coluna,cr.coords[i].linha);
    }
    pontos = max;
  }
  else {
    min = 100;
    for(int i = 0;i < getValidas(&cr);i++) {
      a = jogadaBot(e, &cr.coords[i]);
      if(!p || isOver(&a))
        pontos = avaliaJogada(e,  cr.coords[i]) - 7;
      else
        pontos = minmax(jogadasValidas(&a),a,1,p-1);

      if(pontos < min)
        min = pontos;
    }
    pontos = min;
  }
  return pontos;
}

COORDENADA Bot(ESTADO *e) {
  CVAL cr;
  COORDENADA c;
  int r = 1;
  int best = -100,curr,p;
  ESTADO a;

  cr = jogadasValidas(e);

  for(int i = 0; i < getValidas(&cr) && r;i++) {
    a = jogadaBot(*e, &cr.coords[i]);
    if(isOver(&a) == jogAtual(e))
      return  cr.coords[i];

    curr = minmax(jogadasValidas(&a),a,0,1);

    if(curr > best || (curr == best && avaliaJogada(*e,  cr.coords[i]) > p)) {
      best = curr;
      c =   cr.coords[i];
      p = avaliaJogada(*e,  cr.coords[i]);
    }
    printf("%d%c%d\n", curr,'a' +   cr.coords[i].coluna,  cr.coords[i].linha);
  }
  return c;
}
