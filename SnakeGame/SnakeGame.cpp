// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
#include "GameField.h"
#include "Candy.h"

int FIELD_WIDTH = 15;
int FIELD_HEIGHT = 15;

pair<int, int> generateRandomPosition() {
    srand(time(0));

    return {
        rand() % FIELD_WIDTH,
        rand() % FIELD_HEIGHT
    };
}

int main()
{

    Snake snake(7, 7);
    Candy candy(generateRandomPosition());
    GameField game(FIELD_WIDTH, FIELD_HEIGHT, snake, candy);

    game.DisplayField();

    bool gameOver = false;

    pair<int, int> moveDelta = { 1, 0 };

    while (!gameOver) {
        // Handle movement
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

        // Make snake jump to other side of the map when it hits the wall
        pair<int, int> currentHeadPosition = snake.snakePositions.front();
        if (currentHeadPosition.first < 0) {
            snake.SetPosition({ FIELD_WIDTH - 1, currentHeadPosition.second });
        }
        if (currentHeadPosition.first > FIELD_WIDTH - 1) {
            snake.SetPosition({ 0, currentHeadPosition.second });
        }
        if (currentHeadPosition.second < 0) {
            snake.SetPosition({ currentHeadPosition.first, FIELD_HEIGHT - 1 });
        }
        if (currentHeadPosition.second > FIELD_HEIGHT - 1) {
            snake.SetPosition({ currentHeadPosition.first, 0 });
        }

        // Check if the snake hit a candy
        if (snake.snakePositions.front().first == candy.getPosition().first && snake.snakePositions.front().second == candy.getPosition().second) {
            snake.PickUpCandy();
            candy.setPosition(generateRandomPosition());
        }

        // Check if the snake hit its tail
        list<pair<int, int>> currentSnakePositions = snake.snakePositions;
        if (currentSnakePositions.size() > 1) {
            pair<int, int> headPosition = currentSnakePositions.front();
            currentSnakePositions.pop_front();

            for (pair<int, int> tailPosition : currentSnakePositions) {
                if (headPosition.first == tailPosition.first && headPosition.second == tailPosition.second) {
                    gameOver = true;
                }
            }
        }

        // Update the game field
        game.DisplayField();
        Sleep(200);
    }
}
