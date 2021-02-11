#pragma once
#include "AbstractScene.h"
#include <memory>

class StageBlockMgr;
class UnitMgr;
class PhysicalLaw;

class GameScene final : public AbstractScene
{
private:
	std::shared_ptr<StageBlockMgr> _stageBlockMgr;
	std::shared_ptr<UnitMgr> _unitMgr;
	std::shared_ptr<PhysicalLaw> _physicalLaw;
public:
	explicit GameScene(ISceneChangedListener* const mgr, const nScene::Message&);
	~GameScene();
	void update()override;
	void draw()const override;
	void debugDraw()override;
};

