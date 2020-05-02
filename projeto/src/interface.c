/**
 * @file  interface.c
 * @brief Ficheiro com funções que devolvem resultados visuais para o utilizador
 */
 #include "interface.h"
 #include "time.h"

 /**
  * @brief Função que imprime o menu de comandos
  */
void menu()
{
  printf("-------------------------------------------------\n");
  printf("                     MENU\n");
  printf("-------------------------------------------------\n");
  printf("            Jogar | coordenada <coluna> <linha>\n");
  printf("      Gravar Jogo | gr <nome>\n");
  printf("         Ler Jogo | ler <nome>\n");
  printf("       Movimentos | movs\n");
  printf("   Jogada (Fácil) | jog\n");
  printf(" Jogada (Difícil) | jog2\n");
  printf("          Posição | pos <numero_da_jogada>\n");
  printf("      Mostar Menu | menu\n");
  printf("             Sair | Q\n");
  printf("-------------------------------------------------\n");
}

/**
 * @brief Função que imprime o menu de início
 */
void inicio() {
  system("clear");

  printf("   ____      _    ____ _____ ____   ___  ____   \n");
  printf("  |  _ \\    / \\  / ___|_   _|  _ \\ / _ \\/ ___|  \n");
  printf("  | |_) |  / _ \\ \\___ \\ | | | |_) | | | \\___ \\  \n");
  printf("  |  _ <  / ___ \\ ___) || | |  _ <| |_| |___) | \n");
  printf("  |_| \\_\\/_/   \\_\\____/ |_| |_| \\_\\\\___/|____/  \n\n");

  menu();

  printf("  Bem-vindo ao Rastros. Para jogar utilize os \n");
  printf("  comandos descritos no menu.\n");
  printf("  Para continuar pressione qualquer tecla.\n");
  printf("-------------------------------------------------\n");

  getchar();

  system("clear");
}

/**
 * @brief     Função que imprime o estado do jogo
 * @param e   Apontador para o estado
 * @param com Nºcomandos introduzidos
 */
void printa(ESTADO *e, int com)
{
    int i, j;
    char c = ' ';

    printf("\n  a b c d e f g h\n");

    for (i=0; i<8; i++) {
      printf("%d ", 8-i);

      for (j=0; j<8; j++) {
        switch(getCasa(e, i, j)) {
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
        printf("%c ", c);
      }
      printf("\n");
    }

    printf("#%02d PL%d (%d)\n", com, getjogAtual(e), getnumJogadas(e));
}

/**
 * @brief   Função que verifica se uma String tem espaço
 * @param s String a testa
 * @return  Inteiro com resultado booleano
 */
int temEspaco(char *s) {
  int r = 0;

  for(int i = 0; s[i]!='\0' && !r; i++)
    if(s[i] == ' ')
      r = 1;

  return r;
}

/**
 * @brief   Função que pergunta ao utilizador se quer voltar a jogar
 * @return  Inteiro com resultado booleano
 */
int replay() {
  char* buffer = NULL;
  buffer = malloc(sizeof(char) * MAX);

  printf("\nJogar outra vez? (S/N)\n");

  while(1)
  {
    fgets(buffer, MAX, stdin);

    if(strcmp(buffer, "S\n")==0 || strcmp(buffer, "s\n")==0)
      return 1;

    else if(strcmp(buffer, "N\n")==0 || strcmp(buffer, "n\n")==0)
      return 0;

    else
      printf("\nComando inválido. Jogar outra vez? (S/N)\n");
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

    printf("%02d: ",i);

    if(i == getnumJogadas(e) && getjogAtual(e) == 2) {
      printf("%c%d\n",getultimaJogColuna(e) + 'a', 8 - getultimaJogLinha(e));
    }

    else {
      printf("%c%d %c%d\n",
      getJog1Col(e, i) + 'a', 8 - getJog1Line(e, i),
      getJog2Col(e, i) + 'a', 8 - getJog2Line(e, i));
    }
  }
}

/**
 * @brief   Função que executa o interpretador de comandos
 * @param e Apontador para Estado
 * @param c Apontador para Coordenada
 */
void execute(ESTADO* e, LISTA l, COORDENADA* c)
{
  int j, n = 0, res=0;
  char *buffer = NULL;
  buffer = malloc(MAX*sizeof(char));
  char* s = NULL;
  char *line = NULL, *col = NULL;
  buffer[0] = 'a';
  LISTA aux = NULL;

  inicio();

  gamestart(e);
  l = insere_cabeca(l, (void*)duplicaEstado(e));

  while(1) {
    printa(e, n++);

    printf("\nIntroduza o seu comando: ");
    fgets(buffer, MAX, stdin);

    printf("\n");

    // Intrepertação do comando
    if(!temEspaco(buffer))
      s = strsep(&buffer, "\n");

    else
      s=strsep(&buffer, " ");

    // Execução do comando
    if(strcmp(s, "coordenada") == 0) {
      if(!temEspaco(buffer))
        printf("coordenada inválida\n");

      else {
        col = strsep(&buffer, " ");
        line = strsep(&buffer, "\n");

        if(toCord(c, col, line)) {
          if((aux=place(e, l, c)) != NULL) {
            l = aux;
            aux = NULL;
          }

          else
            printf("Posição inválida.\n");
        }
        else
          printf("Argumentos inválidos\n");
      }
    }

    else if(strcmp(s, "gr") == 0) {
      s = strsep(&buffer, "\n");

      res = output(e,s);

      if(res==-1)
        printf("Erro ao gravaro ficheiro\n");

      else
        printf("Ficheiro %s gravado\n", s);
    }

    else if(strcmp(s, "ler") == 0) {
      s = strsep(&buffer, "\n");

      if((aux=input(e, s, l)) != NULL) {
        l = aux;
        printf("Ficheiro %s lido\n", s);
      }

      else
        printf("Erro ao ler o ficheiro\n");
    }

    else if(strcmp(s, "movs") == 0)
      movimentos(e);

    else if(strcmp(s, "jog") == 0) {
      COORDENADA caux = bot(e);
      l = place(e, l, &caux);
      printf("O Bot jogou na posição %c %d\n", 'a' + getCol(&caux), 8 - getLine(&caux));
    }

    else if(strcmp(s, "jog2") == 0) {
      COORDENADA caux = bot2(e);
      l = place(e, l, &caux);
      printf("O Bot jogou na posição %c %d\n", 'a' + getCol(&caux), 8 - getLine(&caux));
    }

    else if(strcmp(s, "pos") == 0) {
      s = strsep(&buffer, "\n");
      j = atoi(s);

      if(j>=0 && j<getnumJogadas(e)) {
        l = posicao(e, l, j);
        e = (ESTADO*)devolve_cabeca(l);
      }

      else
        printf("\nImpossível voltar à posição %d\n", j);
    }

    else if((strcmp(s, "menu") == 0))
      menu();

    else if((strcmp(s, "q") == 0) || (strcmp(s, "Q") == 0)) {
      printf("\nA Sair do Jogo!\n");
      return;
    }

    else
      printf("Comando Inválido\n");

    // O teste do jogo acabar tem de estar fora, porque se não só na jogada a seguir é que valida
    if ((j = isOver(e))) {

      printa(e, n++);
      printf("\nO vencedor é o jogador %d\n", j);

      if(replay()==0) {
        printf("\nA Sair do Jogo!\n");
        return;
      }

      else {
        inicio();

        gamestart(e);
        l = freeLista(l);
        l = insere_cabeca(l, (void*)duplicaEstado(e));
      }
    }
  }
}
