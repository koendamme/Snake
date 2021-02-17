#include "Snake.h"

using namespace std;

Snake::Snake(int startX, int startY) {
	pair<int, int> initialPosition = { startX, startY };

	snakePositions.push_front(initialPosition);
}

void Snake::Move(pair<int, int> moveDelta) {
	pair<int, int> newHead = GetNewHead(moveDelta, snakePositions.front());
	currentDelta = moveDelta;
	snakePositions.push_front(newHead);
	snakePositions.pop_back();
}

void Snake::PickUpCandy()
{
	pair<int, int> newHead = GetNewHead(currentDelta, snakePositions.front());
	snakePositions.push_front(newHead);
}

void Snake::SetPosition(pair<int, int> newPosition)
{
	snakePositions.front().swap(newPosition);
}

pair<int, int> Snake::GetNewHead(pair<int, int> moveDelta, pair<int, int> currentHeadPosition) {
	pair<int, int> newHead = {
		currentHeadPosition.first + moveDelta.first,
		currentHeadPosition.second + moveDelta.second
	};

	return newHead;
}
