#pragma once
#include "Coordinate.h"

class SmallWindow
{
private:
	Coordinate _coord;
	Coordinate _size;
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void debugDraw() {};
};

