#include "Tama.h"
#include "DxLib.h"
#include "Define.h"
#include "Player.h"
#include "Key.h"
#include "math.h"

Tama::Tama()
{
	reflectS = LoadSoundMem("LoadFile\\Sound\\reflect_se.mp3");
	fallS = LoadSoundMem("LoadFile\\Sound\\fall_se.wav");
	tamaG = LoadGraph("LoadFile\\Graph\\tama2.bmp");
	range = 5;
	_x = Define::GAME_WINDOW_X / 2;
	_y = 400 - range;
	vRandom = GetRand(2);
	vx = 5 - vRandom;
	vy = -(7 - abs(vx));
	remainNum = 3;////////////////////////////////////////////
	collsionPTFlag = 0;
	collsionTBFlag = 0;
	tamaRemainExsit = true;
	flyFlag = 0;
}

Tama::~Tama()
{
}

void Tama::update() {
	if (flyFlag == 0) {
		if (Key::getKeyZ() == 1) {
			PlaySoundMem(reflectS, DX_PLAYTYPE_BACK);
			flyFlag = 1;
		}
	}
	if (flyFlag == 1) {
		_x += vx;
		_y += vy;
		//ï«ÅAìVà‰Ç…ìñÇΩÇ¡ÇΩÇ∆Ç´Ç…íµÇÀï‘ÇÈ
		if (_x - range <= -1) vx *= -1;
		if (_x + range >= Define::GAME_WINDOW_X + 1) vx *= -1;
		if (_y - range <= -1) vy *= -1;
	}
	if (remainNum < 0)tamaRemainExsit = false;
}

void Tama::put(const Player& player)//, Scene& scene)
{
	if (flyFlag == 0) {
		_x = player.getX();
		_y = player.getY() - range;
	}
	if (_y - range >= Define::GAME_WINDOW_Y) {
		PlaySoundMem(fallS, DX_PLAYTYPE_BACK);
		flyFlag = 0;
		remainNum -= 1;
	}
}


void Tama::draw()const
{
	DrawGraph(_x - range, _y - range, tamaG, TRUE);
}

void Tama::CollisionMessagePT()
{	
	if (collsionPTFlag == 0) {
		vy *= -1;
		if (Key::getKeyRight() > 0) {
			if (vx < 0) vx *= -1;
		}
		if (Key::getKeyLeft() > 0) {
			if (vx > 0)vx *= -1;
		}
	}
	collsionPTFlag = 1;
}

void Tama::NotCollsionMessagePT()
{
	collsionPTFlag = 0;
}

//è„
void Tama::CollisionMessageUD() {
	vy *= -1;
}

//âE
void Tama::CollisionMessageLR() {
	vx *= -1;
}

void Tama::NotCollsionMessageTB(){
	collsionTBFlag = 0;
}

void Tama::ChangeVelocity()
{
	if(flyFlag)PlaySoundMem(reflectS, DX_PLAYTYPE_BACK);
	vRandom = GetRand(2);

	if(vx > 0) vx = 5 - vRandom;
	else vx = -(5 - vRandom);
	vy = -(7 - abs(vx));
}
