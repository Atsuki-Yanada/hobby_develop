#include "Looper.h"
#include "Define.h"
#include "Key.h"
#include "SceneMgr.h"
#include "DxLib.h"

Looper::Looper()
{
}

Looper::~Looper()
{
	DeleteSoundMem(looperS);
	DxLib_End();
}

void Looper::process() {
	SceneMgr scenemgr;

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		Key::update();
		scenemgr.update();
		scenemgr.draw();
		scenemgr.debugDraw();


		ScreenFlip();
	}
}

bool Looper::initialize() {
	ChangeWindowMode(TRUE);
	SetMainWindowText("ÉuÉçÉbÉNïˆÇµ");
	SetWindowSizeChangeEnableFlag(FALSE);
	SetGraphMode(Define::GAME_WINDOW_X + Define::SCORE_WINDOW_X, Define::GAME_WINDOW_Y, 32);
	SetWindowSizeExtendRate(1);
	if (DxLib_Init() == -1) return false;
	SetOutApplicationLogValidFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}