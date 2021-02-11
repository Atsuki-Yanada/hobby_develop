#pragma once
#include "AbstractScene.h"

class ConfigScene final : public AbstractScene
{
public:
	explicit ConfigScene(ISceneChangedListener* const mgr, const nScene::Message&);
	~ConfigScene();
	void update()override;
	void draw()const override;
	void debugDraw()override;
};

