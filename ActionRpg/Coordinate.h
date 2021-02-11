#pragma once
#include"Velocity.h"


class Coordinate {
public:
	double _x, _y;
	Coordinate(double x, double y) : _x(x), _y(y) {}
	Coordinate() : _x(0), _y(0) {}

	Velocity operator-(const Coordinate& r) {
		return Velocity(_x - r._x, _y - r._y);
	}
};