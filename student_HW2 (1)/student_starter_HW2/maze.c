#include <stdio.h>
#include "maze.h"

/* 將有效地圖範圍初始化為牆壁，不需修改。 */
void initialize_maze(char maze[][MAX_COLS], int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            maze[row][col] = '#';
        }
    }
}

/* 顯示玩家 @，但不能改動原本的 maze 陣列。 */
void print_maze(char maze[][MAX_COLS], int rows, int cols,
                int player[])
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row == player[0] && col == player[1]) {
                putchar('@');
            } else {
                putchar(maze[row][col]);
            }
        }
        putchar('\n');
    }
}
