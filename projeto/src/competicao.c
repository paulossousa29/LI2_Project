/**
 * @file    competicao.c
 * @brief   Função com a main do bot
 */

#include "data.h"
#include "game.h"
#include "bot.h"
#include "files.h"

/**
 * @brief       Função main do bot
 * @param argc  Número de argumentos do programa
 * @param argv  Array de argumentos do programa
 * @return      Inteiro com o resultado de erro
 */
int main(int argc, char* argv[]) {
    int res;

    if(argc != 3) {
        perror("Número de argumentos inválido");
        return 1;
    }

    ESTADO* e = initEstado();
    LISTA l = NULL;

    l = input(e, argv[1],l);

    if(l==NULL) {
        perror("Ficheiro inválido");
        return 2;
    }

    COORDENADA caux = bot2(e);
    place(e, l, &caux);

    res = output(e, argv[2]);

    if(res==-1) {
        perror("Ficheiro inválidos");
        return 3;
    }

    return 0;
}
