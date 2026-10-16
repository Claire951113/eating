#ifndef GENERATOR_H
#define GENERATOR_H

#include "config.h"

/* Precondition: rows and cols are odd, between 5 and 21. */
/* srand() is called once by main, before calling this function. */
void generate_maze(char maze[][MAX_COLS], int rows, int cols);

#endif
