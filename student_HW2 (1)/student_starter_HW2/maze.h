#ifndef MAZE_H
#define MAZE_H

#include "config.h"

void initialize_maze(char maze[][MAX_COLS], int rows, int cols);
void print_maze(char maze[][MAX_COLS], int rows, int cols,
                int player[]);

#endif
