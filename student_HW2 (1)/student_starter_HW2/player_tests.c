/* Fixed checks for the player API. Do not modify to bypass failures. */
#include <stdio.h>
#include <string.h>
#include "player.h"

static int passed = 0;
static int failed = 0;
static char maze[5][MAX_COLS] = {
    "#####", "#S..#", "###.#", "#..E#", "#####"
};
static int player[2];
static int history[MAX_HISTORY][2];
static int state[2];

static void check(int condition, const char *name)
{
    if (condition) {
        passed++;
    } else {
        failed++;
        printf("FAIL [%02d]: %s\n", passed + failed, name);
        printf("  actual state: player=(%d,%d), cursor=%d, count=%d\n",
               player[0], player[1], state[STATE_CURSOR], state[STATE_COUNT]);
    }
}

/* Initialize independently of reset_player so its bugs do not affect setup. */
static void prepare(int row, int col)
{
    player[0] = row;
    player[1] = col;
    for (int i = 0; i < MAX_HISTORY; i++) {
        history[i][0] = -1;
        history[i][1] = -1;
    }
    history[0][0] = row;
    history[0][1] = col;
    state[STATE_CURSOR] = 0;
    state[STATE_COUNT] = 1;
}

static int move(char command)
{
    return move_player(maze, 5, 5, player, history, state, command);
}

static void check_move(int row, int col, char command, int result,
                       int target_row, int target_col)
{
    prepare(row, col);
    int saved_player[2];
    int saved_history[MAX_HISTORY][2];
    int saved_state[2];
    char saved_maze[5][MAX_COLS];
    memcpy(saved_player, player, sizeof player);
    memcpy(saved_history, history, sizeof history);
    memcpy(saved_state, state, sizeof state);
    memcpy(saved_maze, maze, sizeof maze);
    int actual = move(command);
    int correct = actual == result && player[0] == target_row &&
                  player[1] == target_col;
    if (result == 1) {
        correct = correct && state[STATE_CURSOR] == 1 &&
                  state[STATE_COUNT] == 2 &&
                  history[1][0] == target_row && history[1][1] == target_col &&
                  memcmp(history[0], saved_history[0], sizeof history[0]) == 0 &&
                  memcmp(&history[2], &saved_history[2],
                         sizeof history - 2 * sizeof history[0]) == 0;
    } else {
        correct = correct && memcmp(player, saved_player, sizeof player) == 0 &&
                  memcmp(history, saved_history, sizeof history) == 0 &&
                  memcmp(state, saved_state, sizeof state) == 0;
    }
    correct = correct && memcmp(maze, saved_maze, sizeof maze) == 0;
    char name[120];
    snprintf(name, sizeof name, "move '%c' from (%d,%d): %s", command, row, col,
             result == 1 ? "success" : result == -1 ? "invalid command" :
             "wall or out of bounds");
    check(correct, name);
    if (!correct) {
        printf("  return: expected=%d, actual=%d\n", result, actual);
        printf("  expected state: player=(%d,%d), cursor=%d, count=%d\n",
               target_row, target_col, result == 1 ? 1 : 0, result == 1 ? 2 : 1);
        printf("  history[1]: expected=(%d,%d), actual=(%d,%d)\n",
               result == 1 ? target_row : -1, result == 1 ? target_col : -1,
               history[1][0], history[1][1]);
        if (memcmp(maze, saved_maze, sizeof maze) != 0) {
            puts("  maze changed: movement must preserve the entire map");
        }
        if (result != 1 &&
            memcmp(history, saved_history, sizeof history) != 0) {
            puts("  history changed: a failed move must preserve every entry");
        }
        if (result == 1 &&
            (memcmp(history[0], saved_history[0], sizeof history[0]) != 0 ||
             memcmp(&history[2], &saved_history[2],
                    sizeof history - 2 * sizeof history[0]) != 0)) {
            puts("  unrelated history changed: only the new entry may be written");
        }
    }
}

int main(void)
{
    char original_maze[5][MAX_COLS];
    memcpy(original_maze, maze, sizeof maze);
    puts("[01-21] Commands, movement, bounds and history");
    check_move(1, 1, 'x', -1, 1, 1);
    check_move(1, 1, 'w', 0, 1, 1);
    check_move(1, 1, 'W', 0, 1, 1);
    check_move(1, 1, 'a', 0, 1, 1);
    check_move(1, 1, 'A', 0, 1, 1);
    check_move(1, 1, 'd', 1, 1, 2);
    check_move(1, 1, 'D', 1, 1, 2);
    check_move(1, 2, 'a', 1, 1, 1);
    check_move(1, 2, 'A', 1, 1, 1);
    check_move(1, 3, 's', 1, 2, 3);
    check_move(1, 3, 'S', 1, 2, 3);
    check_move(2, 3, 'w', 1, 1, 3);
    check_move(2, 3, 'W', 1, 1, 3);
    check_move(1, 3, 'd', 0, 1, 3);
    check_move(1, 2, 's', 0, 1, 2);
    check_move(2, 3, 's', 1, 3, 3);
    check_move(3, 2, 'a', 1, 3, 1);
    check_move(0, 2, 'w', 0, 0, 2);
    check_move(4, 2, 's', 0, 4, 2);
    check_move(2, 0, 'a', 0, 2, 0);
    check_move(2, 4, 'd', 0, 2, 4);

    puts("[22-28] Undo and redo");
    prepare(1, 3);
    history[0][0] = 1; history[0][1] = 1;
    history[1][0] = 1; history[1][1] = 2;
    history[2][0] = 1; history[2][1] = 3;
    state[STATE_CURSOR] = 2; state[STATE_COUNT] = 3;
    check(undo_move(player, history, state) == 1 &&
          player[0] == 1 && player[1] == 2 &&
          state[STATE_CURSOR] == 1 && state[STATE_COUNT] == 3,
          "undo changes cursor but preserves count");
    check(history[2][0] == 1 && history[2][1] == 3, "undo retains redo position");
    check(undo_move(player, history, state) == 1 && player[1] == 1 &&
          state[STATE_CURSOR] == 0, "undo to start");
    check(undo_move(player, history, state) == 0 && player[1] == 1 &&
          state[STATE_CURSOR] == 0 && state[STATE_COUNT] == 3,
          "cannot undo before start");
    check(redo_move(player, history, state) == 1 && player[1] == 2 &&
          state[STATE_CURSOR] == 1 && state[STATE_COUNT] == 3, "redo first step");
    check(redo_move(player, history, state) == 1 && player[1] == 3 &&
          state[STATE_CURSOR] == 2, "redo second step");
    check(redo_move(player, history, state) == 0 && player[1] == 3 &&
          state[STATE_CURSOR] == 2 && state[STATE_COUNT] == 3,
          "cannot redo past end");

    puts("[29-35] Failed moves and new branches");
    prepare(1, 1);
    move('d'); move('D'); move('s');
    check(state[STATE_CURSOR] == 3 && state[STATE_COUNT] == 4 &&
          player[0] == 2 && player[1] == 3, "record three successful moves");
    undo_move(player, history, state);
    check(move('d') == 0 && state[STATE_CURSOR] == 2 &&
          state[STATE_COUNT] == 4 && history[3][0] == 2,
          "blocked move preserves redo");
    check(move('x') == -1 && state[STATE_CURSOR] == 2 &&
          state[STATE_COUNT] == 4 && history[3][0] == 2,
          "invalid command preserves redo");
    check(redo_move(player, history, state) == 1 && player[0] == 2,
          "redo remains available after failed moves");
    undo_move(player, history, state);
    check(move('a') == 1 && player[0] == 1 && player[1] == 2 &&
          state[STATE_CURSOR] == 3 && state[STATE_COUNT] == 4 &&
          history[3][0] == 1 && history[3][1] == 2,
          "new branch replaces former future");
    check(redo_move(player, history, state) == 0, "new branch has no redo");
    undo_move(player, history, state);
    undo_move(player, history, state);
    check(move('a') == 1 && state[STATE_CURSOR] == 2 && state[STATE_COUNT] == 3,
          "branch after multiple undos truncates count");

    puts("[36-39] Reset");
    int start[2] = {1, 1};
    reset_player(player, start, history, state);
    check(player[0] == 1 && player[1] == 1 && state[STATE_CURSOR] == 0 &&
          state[STATE_COUNT] == 1 && history[0][0] == 1 && history[0][1] == 1,
          "reset keeps only the start as valid history");
    check(undo_move(player, history, state) == 0, "no undo after reset");
    check(redo_move(player, history, state) == 0, "no redo after reset");
    start[0] = 3; start[1] = 2;
    reset_player(player, start, history, state);
    check(player[0] == 3 && player[1] == 2 && history[0][0] == 3 &&
          history[0][1] == 2, "reset uses the provided start");

    puts("[40-43] History capacity");
    prepare(1, 2);
    for (int i = 0; i < MAX_HISTORY; i++) {
        history[i][0] = 1; history[i][1] = 1;
    }
    history[MAX_HISTORY - 1][1] = 2;
    state[STATE_CURSOR] = MAX_HISTORY - 1;
    state[STATE_COUNT] = MAX_HISTORY;
    check(move('a') == -2 && player[1] == 2 &&
          state[STATE_CURSOR] == MAX_HISTORY - 1 && state[STATE_COUNT] == MAX_HISTORY,
          "full history blocks a new successful move");
    check(move('w') == 0, "wall is checked before capacity");
    check(undo_move(player, history, state) == 1 && player[1] == 1,
          "undo remains available at capacity");
    check(move('d') == 1 && state[STATE_COUNT] == MAX_HISTORY &&
          state[STATE_CURSOR] == MAX_HISTORY - 1 && player[1] == 2,
          "new branch after undo fits the last slot");

    puts("[44-48] Goal and map preservation");
    int goal[2] = {3, 3};
    prepare(1, 1); check(reached_goal(player, goal) == 0, "goal differs");
    prepare(3, 1); check(reached_goal(player, goal) == 0, "goal row only matches");
    prepare(1, 3); check(reached_goal(player, goal) == 0, "goal column only matches");
    prepare(3, 3); check(reached_goal(player, goal) == 1, "both goal coordinates match");

    check(memcmp(maze, original_maze, sizeof maze) == 0,
          "underlying maze remains intact");
    printf("Tests: %d passed, %d failed\n", passed, failed);
    return failed == 0 ? 0 : 1;
}
