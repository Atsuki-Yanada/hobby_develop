#pragma once
#include "AbstractScene.h"

class TitleScene final : public AbstractScene
{
private:
	int decideS;
	int titleG;
	int arrowG;
	int arrowX;
	int arrowY;
	int arrowInterval;
	int branch;
public:
	explicit TitleScene(ISceneChangedListener* const mgr, const nScene::Message&);
	~TitleScene();
	void update()override;
	void draw()const override;
	void debugDraw()override;
};

