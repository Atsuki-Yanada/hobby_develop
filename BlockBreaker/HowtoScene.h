#pragma once
#include "AbstractScene.h"

class HowtoScene final : public AbstractScene
{
private:
	int backS;
	int howtoG;
public:
	explicit HowtoScene(ISceneChangedListener* const mgr, const nScene::Message&);
	~HowtoScene();
	void update()override;
	void draw()const override;
};

