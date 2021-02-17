#pragma once
#include <string>
#include <list>

using namespace std;

class Snake
{
private:
	string currentDirection;
	pair<int, int> GetNewHead(string direction, pair<int, int> currentHeadPosition);

public:
	list<pair<int, int>> snakePositions;
	Snake(int startX, int startY);
	void Move(string direction);
	void PickUpCandy();
};

