#include "SceneMgr.h"
#include "AbstractScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "ConfigScene.h"
#include "HowtoScene.h"
#include "GameClearSceen.h"
#include "GameOverScene.h"

using namespace std;

void SceneMgr::changeScene(const nScene::eScenKind &nextScene, const nScene::Message& message)
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
		case nScene::Howto:
			_scene = make_unique<HowtoScene>(this, _message);
			break;
		case nScene::GameClear:
			_scene = make_unique<GameClearSceen>(this, _message);
			break;
		case nScene::GameOver:
			_scene = make_unique<GameOverScene>(this, _message);
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
