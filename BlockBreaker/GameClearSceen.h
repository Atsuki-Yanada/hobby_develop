#pragma once
#include "AbstractScene.h"

class GameClearSceen final : public AbstractScene
{
private:
	int gameClearG;
public:
	explicit GameClearSceen(ISceneChangedListener *const mgr, const nScene::Message&);
	~GameClearSceen();
	void update()override;
	void draw()const override;
};

