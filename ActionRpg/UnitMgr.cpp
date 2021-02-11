#include "UnitMgr.h"
#include "AbstractUnit.h"
#include "IOnPeepContainer.h"

#include "Player.h"
#include "StageBlock.h"
#include "StoneBlock.h"
#include "WoodBlock.h"

#include <memory>
#include "DxLib.h"

using namespace std;

UnitMgr::UnitMgr(const nBlockMgr::Message& message)
{
	_player = make_shared<Player>();
	_dynamicUnitArray.emplace_back(_player);

	BlockDataContainer block = stageLoader.getStage(message._stageNum);
	for (unsigned int cnt = 0; cnt < block.size(); ++cnt) {
		if (block[cnt]._kind == stageBlockKind::Stone) {
			_staticUnitArray.emplace_back(make_shared<StoneBlock>(block[cnt]._x, block[cnt]._y));
		}
		if (block[cnt]._kind == stageBlockKind::Wood) {
			_dynamicUnitArray.emplace_back(make_shared<WoodBlock>(block[cnt]._x, block[cnt]._y));
		}
	}
}

UnitMgr::~UnitMgr()
{

}

//ヘッダー側の方では IOnPeepCointainer を include していないので ここでコンストラクタを定義している。
IOnPeepContainer UnitMgr::getPeeper()
{
	return IOnPeepContainer(_dynamicUnitArray, _staticUnitArray);
}

void UnitMgr::update()
{
	for (auto& units : _dynamicUnitArray) units->update();
	for (auto& units : _staticUnitArray) units->update();
	
}

void UnitMgr::draw() const
{
	for (auto& units : _dynamicUnitArray) units->draw();
	for (auto& units : _staticUnitArray) units->draw();
}

void UnitMgr::debugDraw()
{
	for (auto& units : _dynamicUnitArray) units->debugDraw();
	for (auto& units : _staticUnitArray) units->debugDraw();
}

std::shared_ptr<Player> UnitMgr::getPlayer()
{
	if (_player) {
		return _player;
	}

	//ここの扱いはあとで
	return std::shared_ptr<Player>();
}
