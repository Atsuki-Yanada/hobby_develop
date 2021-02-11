#pragma once
#include"Drawer.h"

class Camera
{
private:
	float _x, _y;
	std::shared_ptr<IPlayerInfo> _playerInfo;
public:
	Camera(const std::shared_ptr<IPlayerInfo>& playerInfo);
	~Camera();

	float getX() const { return _x; };
	float getY() const { return _y; };


	void update();
	void modifyCoordinate(Drawer::DrawnThing&);
};

