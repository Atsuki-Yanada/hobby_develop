#pragma once
#include "AbstractUnit.h"

class Player;
class Scene;

class Tama: public AbstractUnit
{
private:
	int reflectS;
	int fallS;
	int vRandom;
	int vx;
	int vy;
	int range;
	int tamaG;
	int remainNum;
	bool tamaRemainExsit;
	bool collsionPTFlag;
	bool collsionTBFlag;
	bool flyFlag;
public:
	Tama();
	~Tama();
	void update()override;
	void put(const Player&);//, Scene&);
	void draw()const override;
	void CollisionMessagePT();
	void NotCollsionMessagePT();
	void CollisionMessageUD();
	void CollisionMessageLR();
	void NotCollsionMessageTB();
	void ChangeVelocity();
	int getVx() { return vx; }
	int getVy() { return vy; }
	bool getCollsionTBFlag() { return collsionTBFlag; }
	int getRange()const { return range; }
	int getRemainNum()const { return remainNum; }
	bool getTamaRemainExsit() { return tamaRemainExsit; }
	bool getFlyFlag() { return flyFlag; }
};