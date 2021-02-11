#pragma once

class ISceneChangedListener;

namespace nScene {
	class Message;
}

class AbstractScene
{
protected:
	ISceneChangedListener* _mgr;
public:
	AbstractScene() = delete;
	explicit AbstractScene(ISceneChangedListener* const mgr, const nScene::Message&);
	virtual ~AbstractScene();
	virtual void update() = 0;
	virtual void draw()const = 0;
	virtual void debugDraw() {};
};

