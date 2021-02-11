#include "Combo.h"
#include "Define.h"
#include "DxLib.h"



Combo::Combo()
{
	combo = 0;
}


Combo::~Combo()
{

}

void Combo::draw() const
{
	SetFontSize(26);
	if (combo >= 1) {
		DrawFormatString(Define::GAME_WINDOW_X + 20, 370, GetColor(255, 255, 255), "%2dƒRƒ“ƒ{!", combo);
	}
	SetFontSize(16);
}