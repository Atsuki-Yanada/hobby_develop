#pragma once
#include "StageBlock.h"

class StoneBlock : public StageBlock
{
public:
	StoneBlock(double, double);
	virtual ~StoneBlock();
	void update()override;
	void draw()const override;
	void debugDraw() override;
};

