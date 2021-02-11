#include "TitleScene.h"
#include "ISceneChangedListener.h"
#include "Key.h"
#include "DxLib.h"

TitleScene::TitleScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	decideS = LoadSoundMem("LoadFile\\Sound\\decide_se.wav");
	titleG = LoadGraph("LoadFile\\Graph\\Title.bmp");
	arrowG = LoadGraph("LoadFile\\Graph\\arrow.bmp");
	arrowX = 100;
	arrowY = 420;
	arrowInterval = 180;
	branch = 0;
}


TitleScene::~TitleScene()
{
}

void TitleScene::update()
{
	if (Key::getKeyRight() == 1) {
		PlaySoundMem(decideS, DX_PLAYTYPE_BACK);
		branch++;
		if (branch > 2)branch = 0;
	}
	if (Key::getKeyLeft() == 1) {
		PlaySoundMem(decideS, DX_PLAYTYPE_BACK);
		branch--;
		if (branch < 0)branch = 2;
	}	
	if (branch == 0) {
		if (Key::getKeyZ() == 1) {
			PlaySoundMem(decideS, DX_PLAYTYPE_BACK);
			nScene::Message message;
			_mgr->changeScene(nScene::Game, message);

			return;
		}
	}
	if (branch == 1) {
		if (Key::getKeyZ() == 1) {
			PlaySoundMem(decideS, DX_PLAYTYPE_BACK);
			nScene::Message message;
			_mgr->changeScene(nScene::Howto, message);
			return;
		}
	}
}

void TitleScene::draw()const
{
	DrawGraph(0, 0, titleG, TRUE);
	DrawGraph(arrowX + branch * arrowInterval, arrowY, arrowG, TRUE);
	DrawString(140, 425, "スタート", GetColor(255, 255, 255));
	DrawString(140 + arrowInterval, 425, "あそびかた", GetColor(255, 255, 255));
	DrawString(140 + arrowInterval * 2, 425, "やめる", GetColor(255, 255, 255));
	DrawString(540, 460, "←　→ :移動       Zキー :決定", GetColor(255, 255, 255));
}

void TitleScene::debugDraw()
{
}
