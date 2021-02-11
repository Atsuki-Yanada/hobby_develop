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
	//����if���͈̔͂̓X�e�[�W���ɉ����ĕύX(���݂�1~4�ɂȂ��Ă���)
	if (0 < stageNum && stageNum <= 4) {
		ifstream fin("LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		if (!fin) {
			Error::err("Can not open file LoadFile\\Stage\\stage" + to_string(stageNum) + ".txt");
		}
		
		//�ǉ�2019/12/30////////////////////
		int strCnt = 1, kaigyoCnt = 0;
		string str;
		////////////////////////////////////
		while (fin >> str) {
			//num���󂶂�Ȃ���΁A�u���b�N�f�[�^(x, y, ���)��ǉ�
			//if(str != "0") blockData.emplace_back((cnt%Define::STAGE_BLOCK_NUM_X)*Define::STAGE_BLOCK_SIZE,(cnt / Define::STAGE_BLOCK_NUM_X)*Define::STAGE_BLOCK_SIZE, (stageBlockKind)(stoi(str)));
			
			//�������̌v�Z���������Œ���
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