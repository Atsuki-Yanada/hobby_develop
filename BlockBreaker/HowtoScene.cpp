#include "HowtoScene.h"
#include "ISceneChangedListener.h"
#include "Key.h"
#include "DxLib.h"

HowtoScene::HowtoScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	backS = LoadSoundMem("LoadFile\\Sound\\back_se.wav");
	howtoG = LoadGraph("LoadFile\\Graph\\howto.bmp");
}


HowtoScene::~HowtoScene()
{
}

void HowtoScene::update()
{
	if (Key::getKeyZ() == 1) {
		PlaySoundMem(backS, DX_PLAYTYPE_BACK);
		nScene::Message message;
		_mgr->changeScene(nScene::Title, message);
		return;
	}
}

void HowtoScene::draw() const
{
	DrawGraph(0, 0, howtoG, FALSE);
}
