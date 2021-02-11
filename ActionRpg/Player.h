#pragma once
#include "AbstractUnit.h"

class Player final : public AbstractUnit
{
private:
	double _gravity;
	int _jumpCount;
public:
	Player();
	~Player();
	void update()override;
	void draw()const override;
	void debugDraw() override;
};

