#include "Player.h"
#include "DxLib.h"
#include "Define.h"
#include "Key.h"
#include "Tama.h"

Player::Player()
{
	playerG = LoadGraph("LoadFile\\Graph\\player.bmp");
	_x = Define::GAME_WINDOW_X/2;
	_y = 400;
	vx = 6;
	vy = 1;
	length = 100;
	height = 10;
}


Player::~Player()
{
}

void Player::update()
{
	if(_x + length/2 < Define::GAME_WINDOW_X - 5)
		if (Key::getKeyRight() > 0) _x += vx;
	if(_x - length/2 > 5)
		if (Key::getKeyLeft() > 0) _x -= vx;
}

void Player::update(Tama &tama)
{
	vx = tama.getVx();
	if (vx < 0) vx *= -1;
	if (_x + length / 2 < Define::GAME_WINDOW_X && _x < tama.getX())
		_x += vx;
	if (_x - length / 2 > 0 && _x > tama.getX())
		_x -= vx;
}

void Player::draw()const
{
	DrawGraph(_x - length / 2, _y, playerG, TRUE);
}