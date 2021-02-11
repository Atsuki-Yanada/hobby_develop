#pragma once
#include <vector>
#include <memory>
#include "StageBlockKind.h"


class StageLoader
{
public:
	class BlockData {
	public:
		int _x;
		int	_y;
		stageBlockKind _kind;
		BlockData(int, int, stageBlockKind);
	};

private:
	std::vector<StageLoader::BlockData> blockData;
public:
	StageLoader();
	~StageLoader();
	std::vector<StageLoader::BlockData> getStage(const int);
};


using BlockDataContainer = std::vector<StageLoader::BlockData>;