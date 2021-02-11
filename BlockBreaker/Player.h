#pragma once
#include "AbstractUnit.h"

class Tama;

class Player:public AbstractUnit
{
private :
	int playerG;
	int vx;
	int vy;
	int length;
	int height;
public:
	Player();
	~Player();
	void update() override;
	void update(Tama&);
	void draw()const override;
	int GetLength()const { return length; }
	int GetHegiht()const { return height; }
};