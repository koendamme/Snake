#include "Candy.h"
#include <time.h>

Candy::Candy(pair<int, int> initialPosition) {
	setPosition(initialPosition);
}

pair<int, int> Candy::getPosition()
{
	return position;
}

void Candy::setPosition(pair<int, int> newPosition)
{
	position = newPosition;
}
