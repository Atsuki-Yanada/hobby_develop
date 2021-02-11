#include "Looper.h"
#include "Define.h"
#include "DxLib.h"
#include "SceneMgr.h"
#include "Key.h"

using namespace std;

Looper::Looper()
{
}


Looper::~Looper()
{
}

#include "Timer.h"
#include "Debug.h"
void Looper::process() {
	Timer timer;

	SceneMgr scenemgr;
	bool debugFlag = true;
	while (ProcessMessage() == 0) {
		timer.start("all");
		ClearDrawScreen();
		
		Key::get()->update();
		
		timer.start();
		scenemgr.update();
		Debug::drawString(Debug::format("SceneMgr::update[%f]\n", timer.stop()));

		timer.start();
		scenemgr.draw();
		float timespan = timer.stop();
		Debug::drawString(Debug::format("SceneMgr::draw[%f]\n", timespan));


		//--------------- デバッグモードの切り替え  ESCキー -------------------
		if (Key::get()->getPressingCnt(KEY_INPUT_ESCAPE) == 1) debugFlag = !debugFlag;
		if (debugFlag == true) scenemgr.debugDraw();

		//デバッグ用文字列を表示
		Debug::drawString(Debug::format("All[%f]\n", timer.stop("all")));
		Debug::draw();

		ScreenFlip();
	}
}


/////////////////////////////////  デバッグ用 //////////////////////////////////////////
#include"DispConsole.h"
/////////////////////////////////  デバッグ用 //////////////////////////////////////////

bool Looper::initialize() {
	ChangeWindowMode(TRUE);
	SetMainWindowText("Summon Commander");
	SetWindowSizeChangeEnableFlag(FALSE);
	SetGraphMode(Define::GAME_WINDOW_X, Define::GAME_WINDOW_Y, 32);
	SetWindowSizeExtendRate(1);
	/////////////////////////////////  デバッグ用 //////////////////////////////////////////
	//コンソールの表示
	DispConsole();
	/////////////////////////////////  デバッグ用 //////////////////////////////////////////
	if (DxLib_Init() == -1) return false;
	SetOutApplicationLogValidFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}