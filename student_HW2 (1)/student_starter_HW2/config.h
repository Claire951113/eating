#ifndef CONFIG_H
#define CONFIG_H

#define MIN_SIZE 5
#define MAX_ROWS 21
#define MAX_COLS 21
#define MAX_CELLS (MAX_ROWS * MAX_COLS)
#ifndef MAX_HISTORY
#define MAX_HISTORY 1000
#endif
#define STATE_CURSOR 0 /* 目前位置在歷史紀錄中的索引 */
#define STATE_COUNT 1  /* 有效紀錄數（包含起點） */

#endif
