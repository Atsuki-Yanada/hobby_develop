#include "SceneMgr.h"
#include "AbstractScene.h"
#include "TitleScene.h"
#include "ConfigScene.h"
#include "GameScene.h"
#include "DxLib.h"

using namespace std;

//åpè≥ÇµÇΩISceneChangedListener ÇÃchangeScene ÇíËã`
void SceneMgr::changeScene(const nScene::eSceneKind &nextScene, const nScene::Message &message)
{
	_nextScene = nextScene;
	_message = message;
}

SceneMgr::SceneMgr()
{	
	_scene = make_unique<TitleScene>(this, _message);
	_nextScene = nScene::None;
}


SceneMgr::~SceneMgr()	
{
}

void SceneMgr::update()
{
	_scene->update();
	if (_nextScene != nScene::None) {
		switch (_nextScene) {
		case nScene::Title:
			_scene = make_unique<TitleScene>(this, _message);
			break;
		case nScene::Game:
			_scene = make_unique<GameScene>(this, _message);
			break;
		case nScene::Config:
			_scene = make_unique<ConfigScene>(this, _message);
			break;
		}
		_nextScene = nScene::None;
	}
}

void SceneMgr::draw() const
{
	_scene->draw();
}

void SceneMgr::debugDraw()
{
	_scene->debugDraw();
}

