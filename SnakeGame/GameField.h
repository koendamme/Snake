#pragma once
#include "Snake.h"
#include <vector>
#include <string>

class GameField
{
private:
	int fieldWidth;
	int fieldHeight;
	Snake& snake;
	pair<int, int> candyPosition;

public:
	std::vector<std::vector<std::string>> field;

	GameField(int width, int height, Snake & newSnake);

	void DisplayField();
	pair<int, int> GetCandyPosition() { return candyPosition; }
	void SpawnCandy();
};

