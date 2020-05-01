#include "data.h"
#include "game.h"
#include "minmax.h"
#include "files.h"

int main(int argc, char* argv[]) {
    int res;

    if(argc != 3) {
        perror("Número de argumentos inválido");
        return 1;
    }

    ESTADO* e = initEstado();
    LISTA l = NULL;

    res = input(e, argv[1]);

    if(res==-1) {
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
