#include "ConfigScene.h"
#include "ISceneChangedListener.h"



ConfigScene::ConfigScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
}


ConfigScene::~ConfigScene()
{
}

void ConfigScene::update()
{
}

void ConfigScene::draw()const
{
}

void ConfigScene::debugDraw()
{
}
