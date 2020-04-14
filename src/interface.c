/**
 * @file  interface.c
 * @brief Ficheiro com funções que devolvem resultados visuais para o utilizador
 */

 #include "interface.h"

/**
 * @brief Função que imprime o menu de comandos
 */
void menu()
{
  printf("\nSelecione a sua opção:\n");
  printf("- coordenada <coluna> <linha>\n");
  printf("- gr <nome>\n");
  printf("- ler <nome>\n");
  printf("- tabuleiro\n");
  printf("- movs\n");
  printf("- jog\n");
  printf("- pos <numero_da_jogada>\n");
  printf("- Q\n");
  printf("\nIntroduza o seu comando: ");
}


/**
 * @brief   Função que verifica se uma String tem espaço
 * @param s String a testa
 * @return  Inteiro com resultado booleano
 */
int temEspaco(char *s) {
  int r = 0;
  for(int i = 0;s[i] != '\0' && !r;i++)
    if(s[i] == ' ') r = 1;

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
 * @brief   Função que executa o interpretador de comandos
 * @param e Apontador para Estado
 * @param c Apontador para Coordenada
 */
void execute(ESTADO* e, COORDENADA* c)
{
  int j, r;
  char *buffer = NULL;
  buffer = malloc(MAX*sizeof(char));
  char* s = NULL;
  char *line = NULL, *col = NULL;
  buffer[0] = 'a';

  gamestart(e);

  printa(e); // imprime o estado inicial

  while(1)
  {
    menu();
    fgets(buffer, MAX, stdin);

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
          place(e, c);
          printa(e);
        }
      }
    }

    else if(strcmp(s, "gr") == 0) {
      s = strsep(&buffer, "\n");

      output(e,s);
    }

    else if(strcmp(s, "ler") == 0) {
      s = strsep(&buffer, "\n");

      input(e, s);
    }

    else if(strcmp(s, "tabuleiro") == 0)
      printa(e);

    else if(strcmp(s, "movs") == 0)
      movimentos(e);

    else if(strcmp(s, "jog") == 0) {
      //printf("%s\n", s);
      COORDENADA c;
      c = Bot(e);
      printf("coordenada sugerida %c %d\n", 'a' + getCol(&c), getLine(&c));
    }

    else if(strcmp(s, "pos") == 0) {
      s = strsep(&buffer, "\n");

      posicao(e, s);
    }

    else if((strcmp(s, "q") == 0) || (strcmp(s, "Q") == 0)) {
      printf("\nA Sair do Jogo!\n");
      return;
    }

    else
      printf("Comando Inválido\n");

    // O teste do jogo acabar tem de estar fora, porque se não só na jogada a seguir é que valida
    if ((j = isOver(e))) {
      printf("\nO vencedor é o jogador %d\n", j);

      r = replay();

      if(r==0) {
        printf("\nA Sair do Jogo!\n");
        return;
      }

      else {
        printf("\nNovo Jogo\n");
        gamestart(e);
        printa(e);
      }
    }
  }
}
