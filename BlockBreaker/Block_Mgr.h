#pragma once
#include "Collision.h"
#include "StageLoader.h"
#include <memory>
#include <vector>

class Tama;
class Combo;
class Score;
class Scene;
class Block;

namespace nBlockMgr {
	class Message {
	public:
		int _stageNum;
		Message() : _stageNum(1) {}
	};
}

class Block_Mgr
{
private:
	StageLoader stageLoader;
	std::vector<std::shared_ptr<Block>> _block;
	int _x;
	int _y;
	int length;
	int height;
	int notBreakNum;
	bool blockExist;
	Collision collision;
public:
	Block_Mgr(const nBlockMgr::Message&);
	~Block_Mgr();
	static const int NumX;
	static const int NumY;
	void update(Tama*, Combo*, Score*);//, Scene&);
	void draw()const;
	void debugDraw();
	bool getBlockExist() { return blockExist; }
};