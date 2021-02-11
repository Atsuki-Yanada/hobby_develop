#include "Block.h"
#include "DxLib.h"
#include "Combo.h"



Block::Block(int x, int y)
{
	blockS = LoadSoundMem("LoadFile\\Sound\\break_se.mp3");
	blockG = LoadGraph("LoadFile\\Graph\\block.bmp");
	_x = x;
	_y = y;
	length = 50;
	height = 20;
	_flag = true;
	_hp = 1;
}


Block::~Block()
{
}

void Block::collisionMessage()
{
	PlaySoundMem(blockS, DX_PLAYTYPE_BACK);
	_flag = false;
}

void Block::update() {
}

void Block::draw()const {
	DrawGraph(_x, _y, blockG, FALSE);
}

void Block::debugDraw()
{
	//printfDx("handle = %d\n", blockG);
}

StoneBlock::StoneBlock(int x, int y) : Block(x, y)
{
	blockG = LoadGraph("LoadFile\\Graph\\stone.bmp");
	blockG2 = LoadGraph("LoadFile\\Graph\\stone2.bmp");
	_hp = 2; 
}

void StoneBlock::draw() const
{
	if(_hp == 2)DrawGraph(_x, _y, blockG, FALSE);
	else DrawGraph(_x, _y, blockG2, FALSE);
}

void StoneBlock::collisionMessage()
{
	if (!--_hp) {
		PlaySoundMem(blockS, DX_PLAYTYPE_BACK);
		_flag = false;
	}
}

GoldBlock::GoldBlock(int x, int y)  : Block(x, y)
{
	blockG = LoadGraph("LoadFile\\Graph\\gold.bmp");
}

void GoldBlock::collisionMessage()
{
}
