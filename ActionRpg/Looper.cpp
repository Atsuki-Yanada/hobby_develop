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


		//--------------- �f�o�b�O���[�h�̐؂�ւ�  ESC�L�[ -------------------
		if (Key::get()->getPressingCnt(KEY_INPUT_ESCAPE) == 1) debugFlag = !debugFlag;
		if (debugFlag == true) scenemgr.debugDraw();

		//�f�o�b�O�p�������\��
		Debug::drawString(Debug::format("All[%f]\n", timer.stop("all")));
		Debug::draw();

		ScreenFlip();
	}
}


/////////////////////////////////  �f�o�b�O�p //////////////////////////////////////////
#include"DispConsole.h"
/////////////////////////////////  �f�o�b�O�p //////////////////////////////////////////

bool Looper::initialize() {
	ChangeWindowMode(TRUE);
	SetMainWindowText("Summon Commander");
	SetWindowSizeChangeEnableFlag(FALSE);
	SetGraphMode(Define::GAME_WINDOW_X, Define::GAME_WINDOW_Y, 32);
	SetWindowSizeExtendRate(1);
	/////////////////////////////////  �f�o�b�O�p //////////////////////////////////////////
	//�R���\�[���̕\��
	DispConsole();
	/////////////////////////////////  �f�o�b�O�p //////////////////////////////////////////
	if (DxLib_Init() == -1) return false;
	SetOutApplicationLogValidFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}