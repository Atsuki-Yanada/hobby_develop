#pragma once
#include "Star.h"

static const int STAR_NUM = 40;

class Star_Mgr
{
private:
	Star *star[STAR_NUM];
public:
	Star_Mgr();
	~Star_Mgr();
	void update();
	void draw();
};