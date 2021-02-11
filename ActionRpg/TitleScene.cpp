#include "TitleScene.h"
#include "ISceneChangedListener.h"
#include "DxLib.h"
#include "Key.h"

TitleScene::TitleScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::update()
{
	if (Key::get()->getPressingCnt(KEY_INPUT_SPACE) == 1) {
		nScene::Message message;
		_mgr->changeScene(nScene::Game, message);
		return;
	}
}

void TitleScene::draw() const
{
	
}

void TitleScene::debugDraw()
{
	DrawString(0, 580, "Title", GetColor(255, 255, 255));
}
