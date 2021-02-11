#pragma once
#include "ObjectData.h"

class PhysicalObject : public ObjectData
{
public:
	void updateCoord(const Coordinate&);
	void updateVec(const Velocity&);
	void updateOnWhere(const OnWhere&);
	void gravitate(bool flag); //èdóÕÇ…ëfíºÇ…è]Ç§Ç‡ÇÃÇÕtrue îΩèdóÕÇ…è]Ç§Ç‡ÇÃÇÕfalse
};