#pragma once
#include "ISceneChangedListener.h"
#include <memory>

class AbstractScene;

class SceneMgr final : public ISceneChangedListener
{
private:
	nScene::eScenKind _nextScene;
	void changeScene(const nScene::eScenKind&, const nScene::Message&) override;
	std::unique_ptr<AbstractScene> _scene;
	nScene::Message _message;
public:
	SceneMgr();
	~SceneMgr();
	void update();
	void draw()const;
	void debugDraw();
};
