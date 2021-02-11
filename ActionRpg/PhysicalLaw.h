#pragma once
#include<memory>
#include "IOnPeepContainer.h"
#include "CollisionDetector.h"

//�O���錾

class PhysicalLaw
{
private:
	IOnPeepContainer _peeper;
	CollisionDetector _collisionDetector;
public:
	PhysicalLaw(IOnPeepContainer peeper) : _peeper(peeper){}
	~PhysicalLaw();
	void applyLaw();
};

