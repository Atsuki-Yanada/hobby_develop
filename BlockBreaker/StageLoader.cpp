#include <fstream>
#include <string>
#include "StageLoader.h"
#include "Define.h"
#include "Error.h"

using namespace std;

StageLoader::StageLoader()
{
}


StageLoader::~StageLoader()
{
}

std::vector<StageLoader::BlockData> StageLoader::getStage(const int stageNum)
{
	BlockDataContainer blockData;
	//ステージ数に応じて変更
	if (0 < stageNum && stageNum <= 4) {
		//////////////////////////////////////////////////////////
		ifstream fin("LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		if (!fin) {
			Error::err("Can not open file LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		}
		int cnt = 0, num;
		while (fin >> num) {
			if (num != 0) blockData.emplace_back((cnt%Define::BLOCK_NUM_X)*Define::BLOCK_X, (cnt / Define::BLOCK_NUM_X)*Define::BLOCK_Y, (blockKind)num);
			cnt++;
		}
	}
	else {
		Error::err("Can not open file LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
	}
	return blockData;
}

StageLoader::BlockData::BlockData(int x, int y, blockKind num)
{
	_x = x; _y = y; _kind = (blockKind)num;
}

BlockDataContainer StageLoader::getStage1()
{
	BlockDataContainer blockData;
	//////////////////////////////////////////////////////////
	ifstream fin("LoadFile\\Stage\\stage4.txt");
	if (!fin) {
		Error::err("Can not open file LoadFile\\Stage\\stage1.txt");
	}
	int cnt = 0, num;
	while (fin >> num) {
		if (num != 0) blockData.emplace_back((cnt%Define::BLOCK_NUM_X)*Define::BLOCK_X, (cnt/Define::BLOCK_NUM_X)*Define::BLOCK_Y, (blockKind)num);
		cnt++;
	}
	return blockData;
}

std::vector<StageLoader::BlockData> StageLoader::getStage2()
{

	BlockDataContainer blockData;
	ifstream fin("LoadFile\\Stage\\stage2.txt");
	if (!fin) {
		Error::err("Can not open file LoadFile\\Stage\\stage3.txt");
	}
	int cnt = 0, num;
	while (fin >> num) {
		if (num != 0) blockData.emplace_back((cnt%Define::BLOCK_NUM_X)*Define::BLOCK_X, (cnt / Define::BLOCK_NUM_X)*Define::BLOCK_Y, (blockKind)num);
		cnt++;
	}
	return blockData;
}

std::vector<StageLoader::BlockData> StageLoader::getStage3()
{

	BlockDataContainer blockData;
	ifstream fin("LoadFile\\Stage\\stage3.txt");
	if (!fin) {
		Error::err("Can not open file LoadFile\\Stage\\stage3.txt");
	}
	int cnt = 0, num;
	while (fin >> num) {
		if (num != 0) blockData.emplace_back((cnt%Define::BLOCK_NUM_X)*Define::BLOCK_X, (cnt / Define::BLOCK_NUM_X)*Define::BLOCK_Y, (blockKind)num);
		cnt++;
	}
	return blockData;
}