#include "Candy.h"

Candy::Candy() {
	position
}

pair<int, int> RandomPosition() {
	pair<int, int> newPos;
	newPos.first = rand() % fieldWidth;
	newPos.second = rand() % fieldHeight;
}
