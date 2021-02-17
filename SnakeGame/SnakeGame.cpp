// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
#include "GameField.h"


int main()
{
    int FIELD_WIDTH = 15;
    int FIELD_HEIGHT = 15;

    Snake snake(7, 7);
    GameField game(FIELD_WIDTH, FIELD_HEIGHT, snake);

    game.DisplayField();

    bool gameOver = false;

    pair<int, int> moveDelta = { 1, 0 };

    while (!gameOver) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'a') {
                moveDelta = { -1, 0 };
            }
            if (input == 'd') {
                moveDelta = { 1, 0 };
            }
            if (input == 'w') {
                moveDelta = { 0, -1 };
            }
            if (input == 's') {
                moveDelta = { 0, 1 };
            }
        }

        snake.Move(moveDelta);

        pair<int, int> currentHeadPosition = snake.snakePositions.front();
        if (currentHeadPosition.first < 0) {
            snake.SetPosition({ FIELD_WIDTH, currentHeadPosition.second });
        }
        if (currentHeadPosition.first > FIELD_WIDTH) {
            snake.SetPosition({ 0, currentHeadPosition.second });
        }
        if (currentHeadPosition.second < 0) {
            snake.SetPosition({ currentHeadPosition.first, FIELD_HEIGHT });
        }
        if (currentHeadPosition.second > FIELD_HEIGHT) {
            snake.SetPosition({ currentHeadPosition.first, 0 });
        }

        game.DisplayField();
        
        if (snake.snakePositions.front().first == game.GetCandyPosition().first && snake.snakePositions.front().second == game.GetCandyPosition().second) {
            snake.PickUpCandy();
            game.SpawnCandy();
        }

        Sleep(200);
    }
}
