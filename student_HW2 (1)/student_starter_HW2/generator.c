#include <stdlib.h>
#include "maze.h"
#include "generator.h"

void generate_maze(char maze[][MAX_COLS], int rows, int cols)
{
    int stack_row[MAX_CELLS];
    int stack_col[MAX_CELLS];
    int top = 0;
    int dr[4] = {-2, 0, 2, 0};
    int dc[4] = {0, 2, 0, -2};

    initialize_maze(maze, rows, cols);
    maze[1][1] = '.';
    stack_row[top] = 1;
    stack_col[top] = 1;

    while (top >= 0) {
        int row = stack_row[top];
        int col = stack_col[top];
        int candidate[4];
        int count = 0;

        /* A candidate must be an unvisited interior room. */
        for (int direction = 0; direction < 4; direction++) {
            int next_row = row + dr[direction];
            int next_col = col + dc[direction];
            if (next_row > 0 && next_row < rows - 1 &&
                next_col > 0 && next_col < cols - 1 &&
                maze[next_row][next_col] == '#') {
                candidate[count] = direction;
                count++;
            }
        }

        if (count == 0) {
            top--;  /* No unvisited neighbor: return to the previous room. */
        } else {
            int direction = candidate[rand() % count];
            int next_row = row + dr[direction];
            int next_col = col + dc[direction];

            /* Open the wall between the rooms, then the next room. */
            maze[(row + next_row) / 2][(col + next_col) / 2] = '.';
            maze[next_row][next_col] = '.';
            top++;
            stack_row[top] = next_row;
            stack_col[top] = next_col;
        }
    }

    maze[1][1] = 'S';
    maze[rows - 2][cols - 2] = 'E';
}
