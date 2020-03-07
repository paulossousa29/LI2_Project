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

typedef struct coord
{
  int line;
  int col;
} COORD;

typedef struct state
{
    int player;
    COORD curr;
    VALUE table[8][8];
} STATE;

// Functions

void place(STATE* e, COORD* c, char* col, char* line);

void input(STATE* e, char* name);
void output(STATE* e, char* name);

void printa(STATE *e);
void gamestart(STATE *e);

void menu();
void execute(char* buffer, STATE* e, COORD* c);
