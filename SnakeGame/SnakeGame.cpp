// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
#include "GameField.h"


int main()
{
    Snake snake(7, 7);

    GameField game(15, 15, snake);

    game.DisplayField();

    string direction = "right";

    while (true) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'a') {
                direction = "left";
            }
            if (input == 'd') {
                direction = "right";
            }
            if (input == 'w') {
                direction = "up";
            }
            if (input == 's') {
                direction = "down";
            }
        }

        snake.Move(direction);
        game.DisplayField();
        
        if (snake.snakePositions.front().first == game.GetCandyPosition().first && snake.snakePositions.front().second == game.GetCandyPosition().second) {
            snake.PickUpCandy();
            game.SpawnCandy();
        }

        Sleep(20);
    }
}
