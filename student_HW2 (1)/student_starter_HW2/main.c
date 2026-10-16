#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"
#include "generator.h"
#include "player.h"

/* 主程式：讀尺寸 -> 生成迷宮 -> 讀指令 -> 呼叫 player.c。
   閱讀呼叫流程即可，不需修改。 */
int main(void)
{
    char maze[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int start[2] = {1, 1};
    int player[2] = {1, 1};
    int history[MAX_HISTORY][2];
    int state[2] = {0, 1};  /* 目前索引 = 0，有效紀錄數 = 1 */
    history[0][0] = start[0];
    history[0][1] = start[1];

    printf("Rows and columns (odd 5..21): ");
    fflush(stdout);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < MIN_SIZE || rows > MAX_ROWS ||
        cols < MIN_SIZE || cols > MAX_COLS ||
        rows % 2 == 0 || cols % 2 == 0) {
        puts("Invalid size");
        return 1;
    }
    int goal[2] = {rows - 2, cols - 2};
    srand((unsigned int)time(NULL));
    generate_maze(maze, rows, cols); /* 迷宮生成已完成，不需實作 */

    puts("W/A/S/D + Enter: move; Z: undo; Y: redo; R: reset; Q: quit");
    puts("#: wall  .: path  S: start  E: goal  @: player");
    print_maze(maze, rows, cols, player);
    printf("Steps: %d  Undo: %d  Redo: %d\n", state[STATE_CURSOR],
           state[STATE_CURSOR], state[STATE_COUNT] - state[STATE_CURSOR] - 1);

    while (!reached_goal(player, goal)) {
        char command;
        printf("Command: ");
        fflush(stdout);
        if (scanf(" %c", &command) != 1) {
            puts("Input ended");
            return 0;
        }
        if (command == 'q' || command == 'Q') {
            puts("Game ended");
            return 0;
        } else if (command == 'z' || command == 'Z') {
            if (!undo_move(player, history, state)) {
                puts("Nothing to undo");
            }
        } else if (command == 'y' || command == 'Y') {
            if (!redo_move(player, history, state)) {
                puts("Nothing to redo");
            }
        } else if (command == 'r' || command == 'R') {
            reset_player(player, start, history, state);
            puts("Reset to start");
        } else {
            int result = move_player(maze, rows, cols, player,
                                     history, state, command);
            if (result == 0) {
                puts("Blocked");
            } else if (result == -1) {
                puts("Invalid command");
            } else if (result == -2) {
                puts("History full");
            }
        }
        print_maze(maze, rows, cols, player);
        printf("Steps: %d  Undo: %d  Redo: %d\n", state[STATE_CURSOR],
               state[STATE_CURSOR], state[STATE_COUNT] - state[STATE_CURSOR] - 1);
    }

    printf("You escaped in %d steps!\n", state[STATE_CURSOR]);
    return 0;
}
