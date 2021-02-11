#include "CollisionDetector.h"
#include "PhysicalObject.h"
#include "DxLib.h"

#include "Debug.h"

using namespace std;

CollisionDetector::CollisionDetector()
{
}


CollisionDetector::~CollisionDetector()
{
}

//DynamicUnit Ç∆ StaticUnit Ç∆ÇÃìñÇΩÇËîªíËÇÃä÷êî

void CollisionDetector::applyDS(const std::shared_ptr<PhysicalObject>& U1, const std::shared_ptr<PhysicalObject>& U2)
{	
	//U2ÇÃíÜÇ…ì¸Ç¡ÇΩÇ©Ç«Ç§Ç©ÇÃîªíË
	if (U1->getCoord()._y + U1->getSize() > U2->getCoord()._y &&
		U1->getCoord()._y < U2->getCoord()._y + U2->getSize() &&
		U1->getCoord()._x + U1->getSize() > U2->getCoord()._x &&
		U1->getCoord()._x < U2->getCoord()._x + U2->getSize()) {

		OnWhere nowOnWhere(U1->getOnWhere()._ground, U1->getOnWhere()._ceiling, U1->getOnWhere()._right, U1->getOnWhere()._left);
		Velocity nowVec(U1->getVec()._x, U1->getVec()._y);
		Coordinate preCoord(U1->getCoord()._x - U1->getVec()._x, U1->getCoord()._y - U1->getVec()._y);
		Coordinate nowCoord(U1->getCoord()._x, U1->getCoord()._y);

		//U1ÇÃâEë§Ç∆ç∂ë§ÇÃîªíË
		if (preCoord._y < U2->getCoord()._y + U2->getSize() && preCoord._y + U1->getSize() > U2->getCoord()._y) {
			if (U1->getVec()._x > 0.0 && !nowOnWhere._right) {
				nowCoord._x = U2->getCoord()._x - U1->getSize();
				nowOnWhere._right = true;
			}
			if (U1->getVec()._x < 0.0 && !nowOnWhere._left) {
				nowCoord._x = U2->getCoord()._x + U2->getSize();
				nowOnWhere._left = true;
			}
			nowVec._x = 0.0;
			
		}

		//U1ÇÃè„ë§Ç∆â∫ë§ÇÃîªíË
		if (preCoord._x < U2->getCoord()._x + U2->getSize() && preCoord._x + U1->getSize() > U2->getCoord()._x) {
			if (U1->getVec()._y > 0 && !nowOnWhere._ground) {
				nowCoord._y = U2->getCoord()._y - U1->getSize();
				nowOnWhere._ground = true;
			}
			if (U1->getVec()._y < 0 && !nowOnWhere._ceiling) {
				nowCoord._y = U2->getCoord()._y + U2->getSize();
				nowOnWhere._ceiling = true;
			}
			nowVec._y = 0;
		}
		U1->updateOnWhere(nowOnWhere);
		U1->updateCoord(nowCoord);
		U1->updateVec(nowVec);
	}
}


void CollisionDetector::applyDD(const std::shared_ptr<PhysicalObject>& U1, const std::shared_ptr<PhysicalObject>& U2)
{
	//U2ÇÃíÜÇ…ì¸Ç¡ÇΩÇ©Ç«Ç§Ç©ÇÃîªíË
	if (U1->getCoord()._y + U1->getSize() > U2->getCoord()._y &&
		U1->getCoord()._y < U2->getCoord()._y + U2->getSize() &&
		U1->getCoord()._x + U1->getSize() > U2->getCoord()._x &&
		U1->getCoord()._x < U2->getCoord()._x + U2->getSize()) {

		OnWhere nowOnWhereU1(U1->getOnWhere()._ground, U1->getOnWhere()._ceiling, U1->getOnWhere()._right, U1->getOnWhere()._left);
		Velocity nowVecU1(U1->getVec()._x, U1->getVec()._y);
		Coordinate preCoordU1(U1->getCoord()._x - U1->getVec()._x, U1->getCoord()._y - U1->getVec()._y);
		Coordinate nowCoordU1(U1->getCoord()._x, U1->getCoord()._y);

		OnWhere nowOnWhereU2(U2->getOnWhere()._ground, U2->getOnWhere()._ceiling, U2->getOnWhere()._right, U2->getOnWhere()._left);
		Velocity nowVecU2(U2->getVec()._x, U2->getVec()._y);
		Coordinate preCoordU2(U2->getCoord()._x - U2->getVec()._x, U2->getCoord()._y - U2->getVec()._y);
		Coordinate nowCoordU2(U2->getCoord()._x, U2->getCoord()._y);

		//U1ÇÃâEë§Ç∆ç∂ë§ÇÃîªíË
		if (preCoordU1._y < U2->getCoord()._y + U2->getSize() && preCoordU1._y + U1->getSize() > U2->getCoord()._y) {
			if (U1->getVec()._x > 0 && !nowOnWhereU1._right) {
				nowCoordU1._x = U2->getCoord()._x - U1->getSize();
				//nowCoordU2._x = U1->getCoord()._x + U1->getSize();
				nowOnWhereU1._right = true;
				nowOnWhereU2._left = true;
			}
			if (U1->getVec()._x < 0 && !nowOnWhereU1._left) {
				nowCoordU1._x = U2->getCoord()._x + U2->getSize();
				//nowCoordU2._x = U1->getCoord()._x - U2->getSize();
				nowOnWhereU1._left = true;
				nowOnWhereU2._right = true;
			}
			nowVecU1._x = 0;
			nowVecU2._x = 0;
		}

		//U1ÇÃè„ë§Ç∆â∫ë§ÇÃîªíË
		if (preCoordU1._x < U2->getCoord()._x + U2->getSize() && preCoordU1._x + U1->getSize() > U2->getCoord()._x) {
			if (U1->getVec()._y > 0 && !nowOnWhereU1._ground) {
				nowCoordU1._y = U2->getCoord()._y - U1->getSize();
				nowOnWhereU1._ground = true;
				nowOnWhereU2._ceiling = true;
			}
			if (U1->getVec()._y < 0 && !nowOnWhereU1._ceiling) {
				nowCoordU1._y = U2->getCoord()._y + U2->getSize();
				nowOnWhereU1._ceiling = true;
				nowOnWhereU2._ground = true;
			}
			nowVecU1._y = 0;
			nowVecU2._y = 0;
		}
		U1->updateOnWhere(nowOnWhereU1);
		U1->updateCoord(nowCoordU1);
		U1->updateVec(nowVecU1);

		U2->updateOnWhere(nowOnWhereU2);
		U2->updateCoord(nowCoordU2);
		U2->updateVec(nowVecU2);
	}
}
