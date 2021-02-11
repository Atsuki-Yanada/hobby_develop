#pragma once
#include"PhysicalObject.h"

class AbstractUnit : public PhysicalObject
{
public:
	AbstractUnit();
	virtual ~AbstractUnit();
	virtual void update() = 0;
	virtual void draw()const = 0;
	virtual void debugDraw() {}
};

