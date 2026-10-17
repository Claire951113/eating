#include "player.h"

/* 完成五個函式，保留原有介面。
 * player[0] 為列，player[1] 為欄；歷史包含起點。
 * (void) 和暫時回傳值僅讓骨架能編譯，不代表已完成。
 * 詳細規格請參考 player.h 與「作業說明與教學.md」。
 */
 //測試註解修改
int move_player(char maze[][MAX_COLS], int rows, int cols,
                int player[], int history[][2], int state[], char command)
{
    /* TODO：
     * 1. 暫存預計座標，辨認 WASD（大小寫皆可）；非法命令回傳 -1。
     * 2. 先檢查邊界再讀地圖；越界或撞牆回傳 0。
     * 3. 依下一筆索引檢查容量；無法寫入回傳 -2。
     * 4. 成功才更新歷史、玩家、目前索引及有效筆數，回傳 1。
     * 失敗不可改動 player、history、state；不可修改 maze。
     */

    (void)maze; (void)rows; (void)cols; (void)player;
    (void)history; (void)state; (void)command;

    int next_r = player[0];
    int next_c = player[1];

    if (command == 'W' || command == 'w') {
        next_r--;
    } else if (command == 'S' || command == 's') {
        next_r++;
    } else if (command == 'A' || command == 'a') {
        next_c--;
    } else if (command == 'D' || command == 'd') {
        next_c++;
    } else {
        return -1;
    }
    
    if (next_r < 0 || next_r >= rows || next_c < 0 || next_c >= cols) {
        return 0; 
    }
    if (maze[next_r][next_c] == '#') {
        return 0; 
    }

    int now_cursor=state[STATE_CURSOR];
    int next_cursor =now_cursor+1;
    if (next_cursor >= MAX_HISTORY) {
        return -2; 
    }
    player[0] = next_r;
    player[1] = next_c;
    history[next_cursor][0] = next_r;
    history[next_cursor][1] = next_c;
    state[STATE_CURSOR] = next_cursor;
    state[STATE_COUNT] = next_cursor + 1; 
    return 1;
}

int undo_move(int player[], int history[][2], int state[])
{
    /* TODO：起點不能撤銷；否則移到上一筆歷史並還原玩家。
     * 保留歷史內容與有效筆數；成功回傳 1，無法操作回傳 0。
     */
    (void)player; (void)history; (void)state;
    int now_cursor=state[STATE_CURSOR];
    int count = state[STATE_COUNT];
    if (now_cursor + 1 >= count) {
        return 0;
    }
    now_cursor++;
    state[STATE_CURSOR] = cursor;
    player[0] = history[now_cursor][0];
    player[1] = history[now_cursor][1];
    return 1;
}

int redo_move(int player[], int history[][2], int state[])
{
    /* TODO：有下一筆有效歷史才移動索引並還原玩家。
     * 保留歷史內容與有效筆數；成功回傳 1，無法操作回傳 0。
     */
    (void)player; (void)history; (void)state;
    int now_cursor = state[STATE_CURSOR];
    int count = state[STATE_COUNT];

    if (now_cursor + 1 >= count) {
        return 0;
    }
    now_cursor++;
    state[STATE_CURSOR] = now_cursor;
    player[0] = history[now_cursor][0];
    player[1] = history[now_cursor][1];
    return 1;
}

void reset_player(int player[], int start[], int history[][2], int state[])
{
    /* TODO：依 start 更新玩家與首筆歷史，設定初始索引及有效筆數。
     * 不必清空整個 history，不能把起點固定寫死。
     */
    (void)player; (void)start; (void)history; (void)state;
    player[0] = start[0];
    player[1] = start[1];
    history[0][0] = start[0];
    history[0][1] = start[1];
    state[STATE_CURSOR] = 0;
    state[STATE_COUNT] = 1;
}

int reached_goal(int player[], int goal[])
{
    /* TODO：列與欄皆符合終點時回傳 1，否則回傳 0。 */
    (void)player; (void)goal;
    if (player[0] == goal[0] && player[1] == goal[1]) {
        return 1;
    }
    return 0;
}

