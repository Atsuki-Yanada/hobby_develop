#include "Drawer.h"
#include"Camera.h"
#include<DxLib.h>

using namespace std;


Drawer::Drawer() : _drawnThing(lambda)
{
}


Drawer::~Drawer()
{
}

void Drawer::setUnitManager(const std::shared_ptr<IPlayerInfo>& playerInfo)
{
	_camera = make_unique<Camera>(playerInfo);
}

void Drawer::update()
{
	if(_camera)_camera->update();
}

void Drawer::addDrawnThing(DrawnThing&& drawnThing)
{
	_drawnThing.emplace(drawnThing);
}

void Drawer::draw()
{
	while (!_drawnThing.empty()) {
		DrawnThing work = _drawnThing.top();
		if(_camera)_camera->modifyCoordinate(work);
		
		//DrawRotaGraphF(_drawnThing.top()._x, _drawnThing.top()._y, 1.0, 0.0, _drawnThing.top()._handle, true);

		//¦DrawBox À•W‚Ìˆø”‚Ì•”•ª   double‚©‚çint ‚Ì•ÏŠ·‚É‚È‚Á‚Ä‚é‚¢‚éB 
		DrawBox(work._x, work._y, work._x + work._size, work._y + work._size, work._color, true);
		_drawnThing.pop();
	}
}
