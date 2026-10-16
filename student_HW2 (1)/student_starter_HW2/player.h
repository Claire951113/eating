#ifndef PLAYER_H
#define PLAYER_H

#include "config.h"

/* 說明：player[0] = 列、player[1] = 欄。
 * history[i][0] / [1] = 第 i 筆紀錄的列 / 欄。
 * state[STATE_CURSOR] = 目前索引；state[STATE_COUNT] = 有效筆數。
 * 主程式保證傳入的狀態已完成初始化。
 */

/* W/A/S/D（大小寫皆可）移動一格；不得修改 maze。
 * 回傳：1 成功；0 牆壁/越界；-1 非法指令；-2 歷史容量不足。
 * 失敗不改動 player / history / state；成功的新移動會取消原重做分支。
 */
int move_player(char maze[][MAX_COLS], int rows, int cols,
                int player[], int history[][2], int state[], char command);

/* 撤銷、重做：成功 1、無法操作 0；只移動索引和玩家，不改有效筆數。 */
int undo_move(int player[], int history[][2], int state[]);
int redo_move(int player[], int history[][2], int state[]);

/* 回起點，只保留 history[0] 為有效紀錄；不需清空其他陣列元素。 */
void reset_player(int player[], int start[], int history[][2], int state[]);
/* 玩家列與欄都等於終點才回傳 1，否則回傳 0。 */
int reached_goal(int player[], int goal[]);

#endif
