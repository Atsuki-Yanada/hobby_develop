#include "Score.h"
#include "DxLib.h"
#include "Define.h"
#include "Combo.h"
#include "Tama.h"

Score::Score()
{
	scoreboardG = LoadGraph("LoadFile\\Graph\\scoreboard.bmp");
	score = 0;
}


Score::~Score()
{
}


void Score::update(int combo)
{
	score += 10 + combo * 10;
}

void Score::draw(Tama& tama) const
{
	SetFontSize(26);
	DrawGraph(Define::GAME_WINDOW_X, 0, scoreboardG,FALSE);
	DrawFormatString(Define::GAME_WINDOW_X + 40, 245, GetColor(255, 255, 255), "%5d", score);
	DrawFormatString(Define::GAME_WINDOW_X + 75, 150, GetColor(255, 255, 255), "Å~%d", tama.getRemainNum());
	SetFontSize(16);
}
