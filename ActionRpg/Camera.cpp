#include "Camera.h"
#include "IPlayerInfo.h"
#include "Player.h"
#include "Define.h"
#include <DxLib.h>

Camera::Camera(const std::shared_ptr<IPlayerInfo>& playerInfo) : _playerInfo(playerInfo)
{
	_x = 0; _y = 0;
}


Camera::~Camera()
{
}

void Camera::update()
{
	auto player = _playerInfo->getPlayer();
	if (player) {
		_x = player->getCoord()._x - Define::GAME_WINDOW_X / 2.0;
		//_y = player->getCoord()._y - Define::GAME_WINDOW_Y / 2.0;
		_y = 0;
		if (_x < 0) _x = 0;
		//if (_x < ステージの端) _x = ステージの端;
		if (_y < 0) _y = 0;
		//if (_y < ステージの端) _y = ステージの端;
	}
}

void Camera::modifyCoordinate(Drawer::DrawnThing & thing)
{
	thing._x -= _x;
	thing._y -= _y;
	DrawFormatString(0, 0,GetColor(255, 255, 255),"カメラの座標　x = %f, y = %f", _x, _y);
}
