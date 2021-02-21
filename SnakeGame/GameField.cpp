#include "GameField.h"
#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 

using namespace std;

GameField::GameField(int width, int height, Snake& newSnake, Candy& newCandy) : candy(newCandy), snake(newSnake)  {
	fieldWidth = width;
	fieldHeight = height;
};

void GameField::DisplayField() {
	system("cls");
	for (int i = 0; i < fieldWidth; i++) {
		for (int j = 0; j < fieldHeight; j++) {
			bool snakeAtCurrentPosition = false;
			for (pair<int, int> snakePos : snake.snakePositions) {
				if (snakePos.first == j && snakePos.second == i) {
					snakeAtCurrentPosition = true;
				}
			}

			if (snakeAtCurrentPosition) {
				cout  << "8 ";
			}
			else if (candy.getPosition().first == j && candy.getPosition().second == i) {
				cout << "P ";
			}
			else {
				cout << "_ ";
			}
		}
		cout << "\n";
	}
}
