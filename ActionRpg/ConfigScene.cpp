 #include "ConfigScene.h"
#include "ISceneChangedListener.h"
#include "DxLib.h"


ConfigScene::ConfigScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
}


ConfigScene::~ConfigScene()
{
}

void ConfigScene::update()
{
}

void ConfigScene::draw() const
{
	
}

void ConfigScene::debugDraw()
{
	DrawString(20, 20, "Title", GetColor(255, 255, 255));
}
