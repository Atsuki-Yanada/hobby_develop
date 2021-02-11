#include "PhysicalObject.h"
#include "Debug.h"

void PhysicalObject::updateCoord(const Coordinate& coord)
{
	_coord = coord;
}

void PhysicalObject::updateVec(const Velocity& vec)
{
	_vec = vec;
}

void PhysicalObject::updateOnWhere(const OnWhere& onWhere)
{
	_onWhere = onWhere;
}

void PhysicalObject::gravitate(bool flag)
{
	if (!_onWhere._ground && flag) _vec._y++;
	if (!_onWhere._ceiling && !flag) _vec._y--; //îΩèdóÕ
}