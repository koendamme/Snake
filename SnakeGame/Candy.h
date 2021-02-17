#pragma once
#include <utility>

using namespace std;

class Candy
{
private:
	pair<int, int> RandomPosition();

public:
	pair<int, int> position;

	Candy();

	void NewRandomPosition();
};

