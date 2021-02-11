#pragma once
#include "AbstractUnit.h"
#include "Tama.h"


class Combo;

class Block:public AbstractUnit
{
protected:
	int _hp;
	Tama* tama;
	int blockS;
	int blockG;
	int length;
	int height;
	bool _flag;
public:
	Block(int, int);
	virtual ~Block();
	virtual void collisionMessage();
	bool getFlag()const { return _flag; }
	int getHeight()const { return height; }
	int getLength()const { return length; }
	void update()override;
	virtual void draw()const;
	void debugDraw() override;
};

class StoneBlock final : public Block {
private :
	int blockG2;
public:
	StoneBlock(int, int);
	void draw()const override;
	void collisionMessage() override;
};

class GoldBlock final : public Block {
public :
	GoldBlock(int, int);
	void collisionMessage() override;
};