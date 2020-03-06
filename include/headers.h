// Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define

#define MAX 40
#define SMAX 20

// Structs

typedef enum {EMPTY, CURRENT, OCCUPIED} VALUE;

typedef struct state
{
    VALUE table[8][8];
} STATE;

// Functions

void input(STATE* e, char* name);

void printa(STATE *e);
void gamestart(STATE *e);

void menu();
void execute(char* buffer, STATE* e);
