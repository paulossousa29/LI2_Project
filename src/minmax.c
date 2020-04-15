/**
 * @file    minmax.c
 * @brief   Módulo que contém a implementação das funções que utilizam a eurística minmax
 */

#include "minmax.h"

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

ESTADO jogadaBot(ESTADO e,COORDENADA *c) {
  setCasa(&e,PRETA,getultimaJogLinha(&e),getultimaJogColuna(&e));
  setCasa(&e,BRANCA,c->linha, c->coluna);
  setUltimaJog(&e, c->linha, c->coluna);

  if(getjogAtual(&e) == 1)
    setJogAtual(&e, 1);
  else
    setJogAtual(&e, 2);

  return e;
}

int pertoFim(COORDENADA c,int jogador) {
  if(((c.linha == 0 && c.coluna == 6) || (c.linha == 1 && c.coluna == 6) ||
    (c.linha == 1 && c.coluna == 7)) && jogador == 1)
    return 1;

  if(((c.linha == 6 && c.coluna == 0) || (c.linha == 6 && c.coluna == 1) ||
    (c.linha == 7 && c.coluna == 1)) && jogador == 2)
    return 1;

  return 0;
}

int avaliaJogada(ESTADO e,COORDENADA c) {
  int j = getjogAtual(&e),p;
  ESTADO a = jogadaBot(e,&c);
  int l = getultimaJogLinha(&e),cl = getultimaJogColuna(&e);

  p = isOver(&a);
  if(p != j && p)
    p = 1;
  else if(p == j)
          p = 8;
  else if((pertoFim(c,j)))
          p = 2;
  else if((j == 2 && c.linha == l - 1 && c.coluna == cl + 1) ||
          (j == 1 && c.linha == l + 1 && c.coluna == cl - 1))
          p = 7;
  else if((l == c.linha) && ((j == 2 && c.coluna == cl + 1) ||
          (j == 1 && c.coluna == cl - 1)))
          p = 5;
  else if((cl == c.coluna) && ((j == 2 && c.linha == l - 1) ||
          (j == 1 && c.linha == l + 1)))
          p = 6;
  else if((c.linha == l - 1 && c.coluna == cl - 1) ||
          (c.linha == l + 1 && c.coluna == cl + 1))
          p = 4;
  else p = 3;

  return p;
}

int minmax(LISTA l,ESTADO e,int isMax,int p) {
  int pontos,max = -1000,min = 1000;
  ESTADO a;
  COORDENADA *c;
  LISTA aux;

  if (isMax) {
    for(aux = l;aux;aux = proximo(aux)) {
      c = (COORDENADA*)devolve_cabeca(aux);
      a = jogadaBot(e, c);
      if(!p || isOver(&a))
        pontos = avaliaJogada(e, *c);
      else
        pontos = minmax(jogadasValidas(&a),a,0,p-1);

      if(pontos > max)
        max = pontos;
      //printf("-%d%c%d \n", pontos,'a' + cr.coords[i].coluna,cr.coords[i].linha);
    }
    pontos = max;
  }
  else {
    for(aux = l;aux;aux = proximo(aux)) {
      c = (COORDENADA*)devolve_cabeca(aux);
      a = jogadaBot(e, c);
      if(!p || isOver(&a))
        pontos = avaliaJogada(e, *c) - 7;
      else
        pontos = minmax(jogadasValidas(&a),a,1,p-1);

      if(pontos < min)
        min = pontos;
    }
    pontos = min;
  }
  return pontos;
}

COORDENADA bot(ESTADO *e) {
  LISTA l,aux;
  COORDENADA c,*c2;
  int r = 1, t;
  int best = -100,curr,p;
  ESTADO a;

  l = jogadasValidas(e);

  for(aux = l;aux!= NULL;aux = proximo(aux)) {
    c2 = (COORDENADA*)devolve_cabeca(aux);
    a = jogadaBot(*e,c2);
    printf(".\n" );
    t = isOver(&a);
    if(t == getjogAtual(e))
      return *c2;

    else if (t != 0 || getnumJogadas(e) < 5)
      curr = avaliaJogada(*e,*c2);

    else
      curr = minmax(jogadasValidas(&a),a,0,3);

    if(curr > best || (curr == best && avaliaJogada(*e, *c2) > p)) {
      best = curr;
      c =   *c2;
      p = avaliaJogada(*e, *c2);
    }
    //printf("%d%c%d\n", curr,'a' +   cr.coords[i].coluna,  cr.coords[i].linha);
  }
  return c;
}
