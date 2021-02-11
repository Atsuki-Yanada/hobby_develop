#pragma once
#include <vector>
#include <memory>
#include <stdexcept> //�Ȃ� #include <exception>�@�œ����Ȃ��������炱�̍s��ǉ�����(���Ԃ�o�[�W�����̖��)

//�O���錾
class AbstractUnit;

class IOnPeepContainer {
private:
	//UnitMgr �� _unit ��m���Ă�@���Q�Ƃœn����Ă���
	
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