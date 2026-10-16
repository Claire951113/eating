# 建置、測試與清理：make / make test / make clean。
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

ifeq ($(OS),Windows_NT)
TARGET = maze_game.exe
TEST_TARGET = player_tests.exe
else
TARGET = maze_game
TEST_TARGET = player_tests
endif

OBJS = main.o maze.o generator.o player.o
TEST_OBJS = player_tests.o player.o

.PHONY: all test clean
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c maze.h generator.h player.h config.h
	$(CC) $(CFLAGS) -c main.c -o main.o

maze.o: maze.c maze.h config.h
	$(CC) $(CFLAGS) -c maze.c -o maze.o

generator.o: generator.c generator.h maze.h config.h
	$(CC) $(CFLAGS) -c generator.c -o generator.o

player.o: player.c player.h config.h
	$(CC) $(CFLAGS) -c player.c -o player.o

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST_TARGET)

player_tests.o: player_tests.c player.h config.h
	$(CC) $(CFLAGS) -c player_tests.c -o player_tests.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
ifeq ($(OS),Windows_NT)
	powershell.exe -NoProfile -Command "$$ErrorActionPreference = 'Stop'; foreach ($$artifact in 'main.o','maze.o','generator.o','player.o','player_tests.o','maze_game','maze_game.exe','player_tests','player_tests.exe') { if (Test-Path -LiteralPath $$artifact) { Remove-Item -LiteralPath $$artifact } }"
else
	rm -f $(OBJS) player_tests.o maze_game maze_game.exe player_tests player_tests.exe
endif

