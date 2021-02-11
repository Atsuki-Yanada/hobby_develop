#include "Player.h"
#include "DxLib.h"
#include "Define.h"
#include "Key.h"
#include "Drawer.h"
#include "Debug.h"

using namespace std;

Player::Player()
{
	_coord._x = 100;
	_coord._y = 100;
	_vec._x = 0;
	_vec._y = 0;
	_size = Define::PLAYER_SIZE;
	_jumpCount = Define::PLAYER_JUMP_COUNT;
}


Player::~Player()
{
}

void Player::update()
{
	_vec._x = 0;
	gravitate(true);
	
	if(_onWhere._ground)_jumpCount = Define::PLAYER_JUMP_COUNT;

	//プレイヤーの入力
	if (Key::get()->getPressingCnt(KEY_INPUT_LEFT)) {
		_vec._x -= 5.0;
	}
	if (Key::get()->getPressingCnt(KEY_INPUT_RIGHT)) {
		_vec._x += 5.0;
	}
	if (Key::get()->getPressingCnt(KEY_INPUT_UP) && _onWhere._ground && _jumpCount >= 1) {
		_vec._y -= 15.0;
		--_jumpCount;
	}
	_onWhere.initialize();

	_coord._x += _vec._x;
	_coord._y += _vec._y;
}

void Player::draw() const
{
	Drawer::DrawnThing dt;
	dt._x = _coord._x;
	dt._y = _coord._y;
	dt._priority = 1.0;//==================================================適当========================
	dt._handle = 0;//_handle;
	dt._size = _size;
	dt._color = GetColor(255, 0, 0);

	Drawer::get()->addDrawnThing(move(dt));
}

void Player::debugDraw()
{
}
