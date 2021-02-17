#pragma once
#include "Snake.h"
#include <vector>
#include <string>
#include "Candy.h"

class GameField
{
private:
	int fieldWidth;
	int fieldHeight;
	Snake& snake;
	Candy& candy;

public:
	std::vector<std::vector<std::string>> field;

	GameField(int width, int height, Snake & newSnake, Candy & newCandy);

	void DisplayField();
};

