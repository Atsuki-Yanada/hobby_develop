#pragma once
#include "ObjectData.h"

class PhysicalObject : public ObjectData
{
public:
	void updateCoord(const Coordinate&);
	void updateVec(const Velocity&);
	void updateOnWhere(const OnWhere&);
	void gravitate(bool flag); //�d�͂ɑf���ɏ]�����̂�true ���d�͂ɏ]�����̂�false
};