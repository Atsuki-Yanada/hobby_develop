#include "Block_Mgr.h"
#include "StageLoader.h"
#include "Block.h"
#include <memory>
#include <DxLib.h>
using namespace std;

const int Block_Mgr::NumX = 12;
const int Block_Mgr::NumY = 8;
Block_Mgr::Block_Mgr(const nBlockMgr::Message& message)
{
	BlockDataContainer block = stageLoader.getStage(message._stageNum);
	//BlockDataContainer block = stageLoader.getStage1();
	blockExist = true;
	notBreakNum = 0;
	for (unsigned int cnt = 0; cnt < block.size();++cnt) {
		if (block[cnt]._kind == blockKind::Wood) {
			_block.emplace_back(make_shared<Block>(block[cnt]._x, block[cnt]._y));
		}
		else if(block[cnt]._kind == blockKind::Stone) {
			_block.emplace_back(make_shared<StoneBlock>(block[cnt]._x, block[cnt]._y));
		}
		else if (block[cnt]._kind == blockKind::Gold) {
			_block.emplace_back(make_shared<GoldBlock>(block[cnt]._x, block[cnt]._y));
			notBreakNum++;
		}
	}
}


Block_Mgr::~Block_Mgr()
{
}

void Block_Mgr::update(Tama *tama, Combo *combo, Score *score)//, Scene &scene) 
{
	int brokenCnt = 0;
	for (unsigned int cnt = 0; cnt < _block.size(); ++cnt) {
		if (_block[cnt]->getFlag()) {
			collision.updateTB(tama, _block[cnt], combo, score);
		}
		else {
			brokenCnt++;
			if (brokenCnt == _block.size() - notBreakNum) blockExist = false;
		}
	}
}

void Block_Mgr::draw()const
{
	for (unsigned int cnt = 0; cnt < _block.size(); ++cnt) {
		if (_block[cnt]->getFlag()) {
			_block[cnt]->draw();
		}
	}
}

void Block_Mgr::debugDraw()
{
	for (unsigned int cnt = 0; cnt < _block.size(); ++cnt) {
		if (_block[cnt]->getFlag()) {
			_block[cnt]->debugDraw();
		}
	}

}
