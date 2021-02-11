#include "GameScene.h"
#include "ISceneChangedListener.h"
#include "DxLib.h"
#include "Key.h"
#include "StageLoader.h"
#include "UnitMgr.h"
#include "PhysicalLaw.h"
#include "Drawer.h"

using namespace std;

GameScene::GameScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	nBlockMgr::Message stageMes;
	stageMes._stageNum = message._stageNum;
	_unitMgr = make_shared<UnitMgr>(stageMes);
	Drawer::get()->setUnitManager(_unitMgr);
	_physicalLaw = make_unique<PhysicalLaw>(_unitMgr->getPeeper());
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	if (Key::get()->getPressingCnt(KEY_INPUT_SPACE) == 1) {
		nScene::Message message;
		_mgr->changeScene(nScene::Title, message);
		return;
	}

	if (Key::get()->getPressingCnt(KEY_INPUT_M) == 1) {

	}
	else {
		_unitMgr->update();
		_physicalLaw->applyLaw();
	}

	_unitMgr->draw();
	Drawer::get()->update();
}

void GameScene::draw() const
{
	//_unitMgr->draw();

	//=============================================================================
	//今のところゲームシーンでしか使えない
	//=============================================================================
	Drawer::get()->draw();
}

void GameScene::debugDraw()
{
	DrawString(0, 580, "Game", GetColor(255, 255, 255));

	_unitMgr->debugDraw();
}
