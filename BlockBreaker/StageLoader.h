#pragma once
#include <vector>
#include <memory>
#include "BlockKind.h"


class StageLoader
{
public:
	class BlockData {
	public:
		int _x;
		int	_y;
		blockKind _kind;
		BlockData(int, int, blockKind);
	};
	
private:
	std::vector<StageLoader::BlockData> blockData;
public:
	StageLoader();
	~StageLoader();
	std::vector<StageLoader::BlockData> getStage(const int);
	std::vector<StageLoader::BlockData> getStage1();
	std::vector<StageLoader::BlockData> getStage2();
	std::vector<StageLoader::BlockData> getStage3();
};


using BlockDataContainer = std::vector<StageLoader::BlockData>;
