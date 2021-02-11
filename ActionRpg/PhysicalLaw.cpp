#include "PhysicalLaw.h"
#include "PhysicalObject.h"
#include "AbstractUnit.h" //コイツをinclude しないと applyのpeeper.get()が何を返すのか分からなくなるから必要
#include "Debug.h"

using namespace std;
PhysicalLaw::~PhysicalLaw()
{
}

void PhysicalLaw::applyLaw()
{
	

	for (int i = 0; i < _peeper.dynamicUnitsSize(); ++i) {
		for(int j = 0; j < _peeper.staticUnitsSize(); ++j){
			_collisionDetector.applyDS(static_pointer_cast<PhysicalObject>(_peeper.dynamicUnitsGet(i))
								   , static_pointer_cast<PhysicalObject>(_peeper.staticUnitsGet(j)));
		}
	}

	for (int i = 0; i < _peeper.dynamicUnitsSize(); ++i) {
		for (int j = i + 1 ; j < _peeper.dynamicUnitsSize(); ++j) {
			_collisionDetector.applyDD(static_pointer_cast<PhysicalObject>(_peeper.dynamicUnitsGet(i))
				, static_pointer_cast<PhysicalObject>(_peeper.dynamicUnitsGet(j)));
		}
	}

	Debug::drawString(Debug::format("x = %lf, y = %lf \n", _peeper.dynamicUnitsGet(0)->getCoord()._x, _peeper.dynamicUnitsGet(0)->getCoord()._y));
}
