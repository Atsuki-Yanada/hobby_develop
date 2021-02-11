#include "AbstractScene.h"
#include "ISceneChangedListener.h"


AbstractScene::AbstractScene(ISceneChangedListener* const mgr, const nScene::Message& message) : _mgr(mgr)
{
}


AbstractScene::~AbstractScene()
{
}
