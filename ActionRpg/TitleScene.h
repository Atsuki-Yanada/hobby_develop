#pragma once
#include "AbstractScene.h"

class TitleScene final : public AbstractScene
{
public:
	explicit TitleScene(ISceneChangedListener * const mgr, const nScene::Message &message);
	~TitleScene();
	void update()override;
	void draw()const override;
	void debugDraw()override;
};

