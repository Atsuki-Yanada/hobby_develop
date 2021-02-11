#include "StoneBlock.h"
#include "DxLib.h"
#include "Define.h"
#include "Drawer.h"

using namespace std;

StoneBlock::StoneBlock(double x, double y)
{
	_coord._x = x;
	_coord._y = y;
	_size = Define::STAGE_BLOCK_SIZE;
}


StoneBlock::~StoneBlock()
{
}

void StoneBlock::update(){
}

void StoneBlock::draw() const
{
	Drawer::DrawnThing dt;
	dt._x = _coord._x;
	dt._y = _coord._y;
	dt._priority = 1.0;//==================================================“K“–========================
	dt._handle = 0;//_handle;
	dt._size = _size;
	dt._color = GetColor(180, 180, 180);

	Drawer::get()->addDrawnThing(move(dt));
}

void StoneBlock::debugDraw()
{
}