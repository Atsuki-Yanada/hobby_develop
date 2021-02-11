#pragma once
#include "Coordinate.h"
#include "Velocity.h"
#include "OnWhere.h"

class ObjectData {
protected:
	Coordinate _coord;
	Velocity _vec;
	OnWhere _onWhere;
	double _size;
public:
	Coordinate getCoord()const { return _coord; }
	Velocity getVec()const { return _vec; }
	OnWhere getOnWhere()const { return _onWhere; }
	double getSize()const { return _size; }
};
