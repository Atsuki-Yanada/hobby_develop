#pragma once
#include<memory>

//‘O•ûéŒ¾
class PhysicalObject;

class CollisionDetector
{
private:
public:
	CollisionDetector();
	~CollisionDetector();
	void applyDS(const std::shared_ptr<PhysicalObject>&, const std::shared_ptr<PhysicalObject>&);
	void applyDD(const std::shared_ptr<PhysicalObject>&, const std::shared_ptr<PhysicalObject>&);
};

