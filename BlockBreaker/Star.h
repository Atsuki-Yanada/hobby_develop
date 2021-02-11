#pragma once
#include "AbstractUnit.h"

class Star:public AbstractUnit
{
private:
	int _r;
	int vy;
	int count;
	int color;
	int colorRandR;
	int colorRandG;
	int colorRandB;
public:
	Star();
	~Star();
	int getR()const { return _r; };
	void update()override;
	void draw()const override;
};