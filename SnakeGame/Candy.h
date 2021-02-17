#pragma once
#include <utility>

using namespace std;

class Candy
{
private:
	pair<int, int> position;

public:
	Candy(pair<int, int> position);
	pair<int, int> getPosition();
	void setPosition(pair<int, int> position);
};
