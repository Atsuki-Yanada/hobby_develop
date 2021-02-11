#pragma once
#include <vector>
#include <memory>
#include <stdexcept> //なんか #include <exception>　で動かなかったからこの行を追加した(たぶんバージョンの問題)

//前方宣言
class AbstractUnit;

class IOnPeepContainer {
private:
	//UnitMgr の _unit を知ってる　↓参照で渡されている
	
	std::vector<std::shared_ptr<AbstractUnit>>& _dynamicUnits;
	std::vector<std::shared_ptr<AbstractUnit>>& _staticUnits;
public:
	IOnPeepContainer(std::vector<std::shared_ptr<AbstractUnit>>& dynamicUnits,
					 std::vector<std::shared_ptr<AbstractUnit>>& staticUnits) : 
					_dynamicUnits(dynamicUnits),_staticUnits(staticUnits)  {}
	~IOnPeepContainer() = default;

	std::shared_ptr<AbstractUnit> dynamicUnitsGet(int index);
	std::shared_ptr<AbstractUnit> staticUnitsGet(int index);

	unsigned int dynamicUnitsSize() { return _dynamicUnits.size(); }
	unsigned int staticUnitsSize() { return _staticUnits.size(); }
};