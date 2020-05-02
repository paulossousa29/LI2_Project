/**
 * @file    bot.c
 * @brief   Módulo que contém a implementação das funções para os BOTs
 */
#include "bot.h"

/**
 * @brief   Função que cria uma lista de coordenadas válidas
 * @param e Apontador para estado
 * @return    Lista ligada de coordenadas válidas
 */
LISTA jogadasValidas(ESTADO *e) {
  LISTA list;
  int l = getultimaJogLinha(e);
  int c = getultimaJogColuna(e);
  int l2 = l - 1,c2;
  COORDENADA coord;
  list = initLista();

  if(l == 0) l2++;

  for(;l2 <= l + 1 && l2 < 8;l2++) {
    for(c2 = c - 1;c2 <= c + 1;c2++)
      if(c2 >= 0 && c2 <=7 && getCasa(e, l2, c2) == VAZIO) {
        coord.linha = l2;
        coord.coluna = c2;
        list = insere_cabeca(list,(void*)duplicaCOORD(&coord));
      }
  }
  return list;
}

/**
 * @brief   Função que simula uma jogada do bot
 * @param e Estado
 * @param c Apontador para coordenada a jogar
 * @return  Estado
 */
ESTADO jogadaBot(ESTADO e,COORDENADA *c) {
  setCasa(&e,PRETA,getultimaJogLinha(&e),getultimaJogColuna(&e));
  setCasa(&e,BRANCA,c->linha, c->coluna);
  setUltimaJog(&e, c->linha, c->coluna);

  if(getjogAtual(&e) == 1)
    setJogAtual(&e, 2);
  else {
    setJogAtual(&e, 1);
    setNJogadas(&e,getnumJogadas(&e)+1);
  }

  return e;
}

/**
 * @brief   Função que analisa se a coordenada esta perto do 1 ou do 2
 * @param c Coordenada a jogar
 * @return    Int que é 1 se perto do 1,2 se perto de 2 ou 0
 */
int pertoFim(COORDENADA c) {
  if(((c.linha == 0 && c.coluna == 6) || (c.linha == 1 && c.coluna == 6) ||
    (c.linha == 1 && c.coluna == 7)))
    return 2;

  if(((c.linha == 6 && c.coluna == 0) || (c.linha == 6 && c.coluna == 1) ||
    (c.linha == 7 && c.coluna == 1)))
    return 1;

  return 0;
}

/**
 * @brief    Função que atribiu uma pontuação a uma jogada
 * @param l  Linha ultima_jogada
 * @param cl Coluna ultima_jogada
 * @param c  Coordenada a jogar
 * @param j  Jogador atual
 * @return     Int correspondente à pontuação da jogada
 */
int avalia(int l,int cl,COORDENADA c,int j) {
  int p;
  if(c.linha == l - 1) {
    if(c.coluna == cl - 1){
      if((l == 0 && cl < 4 && j == 2) || (cl == 7 && l < 5 && j == 1)) p = 7;
      else p = 5;
    }
    else if(c.coluna == cl + 1){
      if(j == 1) p = 6;
      else p = 4;
    }
    else {
      if(j == 1) p = 7;
      else p = 4;
    }
  }
  else if(c.linha == l + 1){
    if(c.coluna == cl - 1){
      if(j == 2) p = 6;
      else p = 4;
    }
    else if(c.coluna == cl + 1){
      if((cl == 0 && l > 4 && j == 2) || (l == 0 && cl > 4 && j == 1)) p = 7;
      else p = 5;
    }
    else {
      if(j == 1) p = 4;
      else p = 7;
    }
  }
  else {
    if((c.coluna == cl - 1 && j == 2) || (c.coluna == cl + 1 && j == 1)) p = 5;
    else p = 4;
  }
    return p;
}
/**
 * @brief     Função que atribiu uma pontuação a uma jogada
 * @param e   Estado
 * @param c   Coordenada a jogar
 * @return      Int correspondente à pontuação da jogada
 */
int avaliaJogada(ESTADO e,COORDENADA c) {
  int j = getjogAtual(&e),p,n = getnumJogadas(&e);
  ESTADO a = jogadaBot(e,&c);
  int l = getultimaJogLinha(&e),cl = getultimaJogColuna(&e);

  p = isOver(&a);
  if(p != j && p) p = 1;
  else if(p == j) p = 8;
  else if(n < 5) p = avalia(l,cl,c,j);
  else {
      if(c.linha == l - 1) {
        if(c.coluna == cl - 1){
          if(j == 2) p = 7;
          else p = 5;
        }
        else{
          if(j == 1) p = 6;
          else p = 4;
        }
      }
      else if(c.linha == l + 1){
        if(c.coluna == cl - 1){
          if(j == 2) p = 6;
          else p = 4;
        }
        else if(c.coluna == cl + 1){
          if(j == 1) p = 7;
          else p = 5;
        }
        else {
          if(j == 1) p = 4;
          else p = 6;
        }
      }
      else {
        if((c.coluna == cl - 1 && j == 2) || (c.coluna == cl + 1 && j == 1)) p = 4;
        else p = 7;
      }
    }
  return p;
}

/**
 * @brief       Algoritmo minmax com alpha-beta pruning
 * @param e     Estado
 * @param l     Lista ligada de coordenadas válidas
 * @param isMax Int que é 1 para maximizar a pontuçao ou 0 para minimizar
 * @return        Int correspondente à pontuação da melhor jogada
 */
int minmax(LISTA l,ESTADO e,int isMax,int p,int alpha,int beta) {
  int pontos,max = -1000,min = 1000,r = 1;
  ESTADO a;
  COORDENADA *c;
  LISTA aux;

  if (isMax) {
    for(aux = l;aux && r;aux = proximo(aux)) {
      c = (COORDENADA*)devolve_cabeca(aux);
      a = jogadaBot(e, c);
      if(!p || isOver(&a))
        pontos = avaliaJogada(e, *c);
      else
        pontos = minmax(jogadasValidas(&a),a,0,p-1,alpha,beta);

      if(pontos > max)
        max = pontos;
      if(max >= beta) r = 0;
      if(alpha <= max) alpha = max;
      pontos = max;
    }
  }
  else {
    for(aux = l;aux && r;aux = proximo(aux)) {
      c = (COORDENADA*)devolve_cabeca(aux);
      a = jogadaBot(e, c);
      if(!p || isOver(&a))
        pontos = 9 - avaliaJogada(e, *c);
      else
        pontos = minmax(jogadasValidas(&a),a,1,p-1,alpha,beta);

      if(pontos < min)
        min = pontos;
      if(min <= alpha) r = 0;
      if(beta >= min) beta = min;
    }
    pontos = min;
  }

  return pontos;
}

/**
 * @brief       Funçao que implementa a estratégia dificil do bot
 * @param e     Apontador para o estado
 * @return      Coordenada onde o bot deve jogar
 */
COORDENADA bot2(ESTADO *e) {
  LISTA l,aux;
  COORDENADA c,*c2;
  int t,pf = 9,n;
  int best = -100,curr,p,alpha = -1000,beta = 1000;
  ESTADO a;

  l = jogadasValidas(e);

  for(aux = l;aux!= NULL;aux = proximo(aux)) {
    c2 = (COORDENADA*)devolve_cabeca(aux);
    a = jogadaBot(*e,c2);
    t = isOver(&a);
    n = getnumJogadas(e);

    if(t == getjogAtual(e))
      return *c2;

    else if (t != 0 || n < 3)
      curr = avaliaJogada(*e,*c2);

    else {
      if(n > 5) pf = 11;
      if(n > 11) pf = 13;
      if(n > 18) pf = 15;
      curr = minmax(jogadasValidas(&a),a,0,pf,alpha,beta);
    }

    if(curr > best || (curr == best && avaliaJogada(*e, *c2) > p)) {
      best = curr;
      c =   *c2;
      p = avaliaJogada(*e, *c2);
    }
  }
  return c;
}

/**
 * @brief       Funçao que implementa a estratégia fácil do bot
 * @param e     Apontador para o estado
 * @return      Coordenada onde o bot deve jogar
 */
COORDENADA bot(ESTADO *e) {
  LISTA l = jogadasValidas(e),aux;
  COORDENADA *c,cbest;
  int score,min = 1000;
  int l1 = 0,cl = 7,l2 = 7,c2 = 0,j = getjogAtual(e);

  for(aux = l;aux!= NULL;aux = proximo(aux)) {
    c = (COORDENADA*)devolve_cabeca(aux);
    if(j == 2)
      score = sqrt(pow(l1 - c->linha,2)+pow(cl - c->coluna,2));
    else
      score = sqrt(pow(l2 - c->linha,2)+pow(c2 - c->coluna,2));

    if(score < min) {
      min = score;
      cbest = *c;
    }
  }
  return cbest;
}
