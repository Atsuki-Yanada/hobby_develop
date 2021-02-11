#pragma once
class AbstractUnit
{
protected:
	int _x, _y;
public:
	AbstractUnit();
	virtual ~AbstractUnit();
	virtual void update() = 0;
	virtual void draw()const = 0;
	virtual void debugDraw() {}
	int getX()const { return _x; }
	int getY()const { return _y; }
};