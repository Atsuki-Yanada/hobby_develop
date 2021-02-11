#include "Time.h"
#include "DxLib.h"
#include "Define.h"

const int Time::LIMIT_TIME = 240;

Time::Time()
{
	initFlag = true;
}


Time::~Time()
{
}

void Time::update()
{
	if (initFlag) {
		initTime = GetNowCount();
		initFlag = false;
	}
	nowTime = GetNowCount();
	resultTime = LIMIT_TIME - (nowTime - initTime)/1000;
	
	/* ========================================== É_ÉÅÉ_ÉÅ ====================================
	if (resultTime < 0) scene.gameOver();
	===========================================================================================*/
}

void Time::draw() const
{
	SetFontSize(32);
	DrawFormatString(Define::GAME_WINDOW_X + 45, 45, GetColor(255, 255, 255), "%3d", resultTime);
	SetFontSize(16);
}
