#include "Snake.h"

using namespace std;

Snake::Snake(int startX, int startY) {
	pair<int, int> initialPosition = { startX, startY };

	snakePositions.push_front(initialPosition);
}

void Snake::Move(string direction) {
	pair<int, int> newHead = GetNewHead(direction, snakePositions.front());
	currentDirection = direction;
	snakePositions.push_front(newHead);
	snakePositions.pop_back();
}

void Snake::PickUpCandy()
{
	pair<int, int> newHead = GetNewHead(currentDirection, snakePositions.front());
	snakePositions.push_front(newHead);
}

pair<int, int> Snake::GetNewHead(string direction, pair<int, int> currentHeadPosition) {
	pair<int, int> newHead;

	if (direction == "left") {
		newHead.first = currentHeadPosition.first - 1;
		newHead.second = currentHeadPosition.second;
	}
	else if (direction == "right") {
		newHead.first = currentHeadPosition.first + 1;
		newHead.second = currentHeadPosition.second;
	}
	else if (direction == "up") {
		newHead.first = currentHeadPosition.first;
		newHead.second = currentHeadPosition.second - 1;
	}
	else if (direction == "down") {
		newHead.first = currentHeadPosition.first;
		newHead.second = currentHeadPosition.second + 1;
	}
	else {
		throw "Unknown direction";
	}

	return newHead;
}
