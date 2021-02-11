#include <fstream>
#include <string>
#include "StageLoader.h"
#include "Define.h"
#include "Error.h"
#include "DxLib.h"

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
	//下のif文の範囲はステージ数に応じて変更(現在は1~4になっている)
	if (0 < stageNum && stageNum <= 4) {
		ifstream fin("LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		if (!fin) {
			Error::err("Can not open file LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		}
		
		//追加2019/12/30////////////////////
		int strCnt = 1, kaigyoCnt = 0;
		string str;
		////////////////////////////////////
		while (fin >> str) {
			//numが空じゃなければ、ブロックデータ(x, y, 種類)を追加
			//if(str != "0") blockData.emplace_back((cnt%Define::STAGE_BLOCK_NUM_X)*Define::STAGE_BLOCK_SIZE,(cnt / Define::STAGE_BLOCK_NUM_X)*Define::STAGE_BLOCK_SIZE, (stageBlockKind)(stoi(str)));
			
			//↓ここの計算汚いから後で直す
			if (str != "0"s && str != "/"s) blockData.emplace_back((strCnt - 1) * Define::STAGE_BLOCK_SIZE, kaigyoCnt * Define::STAGE_BLOCK_SIZE, (stageBlockKind)(stoi(str)));
			if (str == "/"s) strCnt = 0, kaigyoCnt++;
			strCnt++;
		}
	}
	else {
		Error::err("Can not open file LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
	}
	return blockData;
}

StageLoader::BlockData::BlockData(int x, int y, stageBlockKind num)
{
	_x = x; _y = y; _kind = (stageBlockKind)num;
}