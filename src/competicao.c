#include "data.h"
#include "game.h"
#include "minmax.h"
#include "files.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        perror("Número de argumentos inválido");
        return 1;
    }

    ESTADO* e = initEstado();
    LISTA l;

    input(e, argv[0]);

    COORDENADA caux = bot(e);
    place(e, l, &caux);

    output(e, argv[1]);

    return 0;
}