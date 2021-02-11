#pragma once
#include "StageLoader.h"
#include "IPlayerInfo.h"
#include <memory>
#include <vector>

//‘O•ûéŒ¾
class AbstractUnit;
class Player;
class StageBlock;

namespace nBlockMgr {
	class Message {
	public:
		int _stageNum;
		Message() : _stageNum(1) {}
	};
}

//‘O•û
class IOnPeepContainer;

class UnitMgr : public IPlayerInfo
{
private:
	std::vector<std::shared_ptr<AbstractUnit>> _staticUnitArray;
	std::vector<std::shared_ptr<AbstractUnit>> _dynamicUnitArray;
	
	StageLoader stageLoader;
	std::shared_ptr<StageBlock> _stageBlock;
	std::shared_ptr<Player> _player;
public:
	UnitMgr(const nBlockMgr::Message& message);
	~UnitMgr();	
	IOnPeepContainer getPeeper();
	void update();
	void draw()const;
	void debugDraw();



	std::shared_ptr<Player> getPlayer();
};

