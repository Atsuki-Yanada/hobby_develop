#include "DxLib.h"
#include "Star.h"
#include "Define.h"
#include <math.h>

Star::Star()
{
	_x = GetRand(Define::GAME_WINDOW_X);
	_y = GetRand(Define::GAME_WINDOW_Y);
	count = 0;
	/////////////////////////////‰F’ˆ”wŒi///////////////////////////////////
	_r = 1;
	vy = GetRand(2) + 1;
	if(GetRand(1) == 0) color = GetColor(50, 200, 200);
	else color = GetColor(200, 200, 200);
	/////////////////,////////////ƒJƒ‰ƒtƒ‹”wŒi///////////////////////////////
	//_r = GetRand(20) + 30;
	//vy = GetRand(2) + 2;
	//colorRandR = GetRand(180), colorRandG = GetRand(180 - colorRandR), colorRandB = GetRand(180 - colorRandR - colorRandG);
	//color = GetColor(75 + colorRandR,75 + colorRandG,75 + colorRandB);
	////////////////////////////////////////////////////////////////////////
}


Star::~Star()
{
}

void Star::update()
{
	
	if (count == 2) {
		_y += vy;
		count = 0;
	}
	
	if (_y >= Define::GAME_WINDOW_Y + _r) {
		_x = GetRand(Define::GAME_WINDOW_X);
		_y = -_r;
	}
	count++;
}

void Star::draw() const
{
	if (count == 2) {
		DrawCircle(_x, _y, _r, color, TRUE);
	}
	/*
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	for (int i = 0; i < 3 * sin(2 * 3.1415926535 * count / 6) + 3; ++i) {
		DrawGraph(_x, _y, graphHandle, color, TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	*/
}
