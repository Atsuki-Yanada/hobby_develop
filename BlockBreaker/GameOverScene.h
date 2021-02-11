#pragma once
#include "AbstractScene.h"

class GameOverScene final : public AbstractScene
{
private:
	int gameOverG;
public:
	explicit GameOverScene(ISceneChangedListener *const mgr, const nScene::Message&);
	~GameOverScene();
	void update() override;
	void draw()const override;
};

