#pragma once
#include <string>
#include <list>

using namespace std;

class Snake
{
private:
	pair<int, int> currentDelta;
	pair<int, int> GetNewHead(pair<int, int> moveDelta, pair<int, int> currentHeadPosition);

public:
	list<pair<int, int>> snakePositions;
	Snake(int startX, int startY);
	void Move(pair<int , int> moveDelta);
	void PickUpCandy();
	void SetPosition(pair<int, int> newPosition);
};

