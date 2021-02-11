#pragma once
#include "StageBlock.h"

class WoodBlock : public StageBlock
{
public:
	WoodBlock(double, double);
	virtual ~WoodBlock();
	void update()override;
	void draw()const override;
	void debugDraw() override;
};

