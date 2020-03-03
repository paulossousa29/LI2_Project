// Structs

typedef enum {VAZIA, SUGESTAO, VALIDA, VALOR_X, VALOR_O} VALOR;

typedef struct estado
{
    VALOR peca;
    VALOR pecabot;
    VALOR grelha[8][8];
    char start; // false 0 | true 1
    char modo; // manual 0 | automático 1
    char nivel; // easy 1 | medium 2 | hardcore 3
} ESTADO;