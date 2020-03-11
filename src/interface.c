#include "data.h"
#include "files.h"
#include "game.h"

// Função que imprime o Estado
void printa(ESTADO *e)
{
    int i, j;
    char c = ' ';

    printf("  a b c d e f g h\n");

    for (i=0; i<8; i++) {
      printf("%d ", 8-i);

      for (j=0; j<8; j++) {
        switch(e->tab[i][j]) {
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
    printf("Jogador: %d\n", e->jogador_atual);
}

// Função que mostra o menu de comandos
void menu()
{
  printf("\nSelecione a sua opção:\n");
  printf("- coordenada <coluna> <linha>\n");
  printf("- gr <nome>\n");
  printf("- ler <nome>\n");
  printf("- imprimir\n");
  printf("- movs\n");
  printf("- jog\n");
  printf("- pos <numero_da_jogada>\n");
  printf("- Q\n");
  printf("\nIntroduza o seu comando: ");
}

// Intrepertador
void execute(ESTADO* e, COORDENADA* c)
{
  char *buffer = NULL;
  buffer = malloc(MAX*sizeof(char));
  char* s = NULL;
  char *line = NULL, *col = NULL;
  buffer[0] = 'a';

  while(toupper(buffer[0])!='Q')
  {
    //printa(e);
    menu();
    fgets(buffer, MAX, stdin);

    s = strsep(&buffer, " ");

    if(strcmp(s, "coordenada") == 0) {
      if (isOver(e) == 1) {
        printf("\n O vencedor é o jogador %d\n", e->jogador_atual);
      }
      else {
      col = strsep(&buffer, " ");
      line = strsep(&buffer, "\n");

      place(e, c, col, line);
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
    else if(strcmp(s, "imprimir\n") == 0) {
      printa(e);
    }

    else if(strcmp(s, "movs") == 0) {
      printf("%s\n", s);
    }

    else if(strcmp(s, "jog") == 0) {
      printf("%s\n", s);
    }

    else if(strcmp(s, "pos") == 0) {
      printf("%s\n", s);
    }

    else if(toupper(s[0]) == 'Q' && s[1] == '\n') {
      printf("A sair do jogo\n");
    }

    else {
      printf("Comando Inválido\n");
    }
/*
    if (isOver(e) == 1) {

      if (e->jogador_atual == 1) e->jogador_atual = 2;
      else if (e->jogador_atual == 2) e->jogador_atual = 1;

      printf("\n O vencedor é o jogador %d\n", e->jogador_atual);
      return;
    }
    */
  }
  printf("A sair do jogo\n");
}
