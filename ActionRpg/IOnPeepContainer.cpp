#include "IOnPeepContainer.h"
//#include <exception>
#include <stdexcept> //なんか #include <exception>　で動かなかったからこの行を追加した(たぶんバージョンの問題)



std::shared_ptr<AbstractUnit> IOnPeepContainer::dynamicUnitsGet(int index)
{
	if (!(index >= 0 && index < _dynamicUnits.size())) throw std::invalid_argument("IOnPeepContainer::get() invalid_argument");
	return _dynamicUnits[index];
}

std::shared_ptr<AbstractUnit> IOnPeepContainer::staticUnitsGet(int index)
{

	if (!(index >= 0 && index < _staticUnits.size())) throw std::invalid_argument("IOnPeepContainer::get() invalid_argument");
	return _staticUnits[index];
}