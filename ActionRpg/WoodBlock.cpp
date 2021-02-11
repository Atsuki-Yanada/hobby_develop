#include "WoodBlock.h"
#include "Drawer.h"
#include "DxLib.h"
#include "Define.h"

using namespace std;

WoodBlock::WoodBlock(double x, double y)
{
	_coord._x = x;
	_coord._y = y;
	_size = 70;
}

WoodBlock::~WoodBlock()
{
}

void WoodBlock::update()
{
	_vec._x = 0;
	gravitate(true);
	if (_onWhere._left) _vec._x++;
	if (_onWhere._right) _vec._x--;

	_onWhere.initialize();

	_coord._x += _vec._x;
	_coord._y += _vec._y;
}

void WoodBlock::draw() const
{
	Drawer::DrawnThing dt;
	dt._x = _coord._x;
	dt._y = _coord._y;
	dt._priority = 1.0;//==================================================“K“–========================
	dt._handle = 0;//_handle;
	dt._size = _size;
	dt._color = GetColor(115, 78, 48);

	Drawer::get()->addDrawnThing(move(dt));
}

void WoodBlock::debugDraw()
{
}
