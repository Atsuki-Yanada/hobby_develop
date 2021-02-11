#include "GameClearSceen.h"
#include "ISceneChangedListener.h"
#include "DxLib.h"
#include "Key.h"
#include "Define.h"


GameClearSceen::GameClearSceen(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	gameClearG = LoadGraph("LoadFile\\Graph\\gameclear.jpg");
}

GameClearSceen::~GameClearSceen()
{
}

void GameClearSceen::update()
{
	if (Key::getKeyZ() == 1) {
		nScene::Message message;
		_mgr->changeScene(nScene::Title, message);
		return;
	}
}

void GameClearSceen::draw() const
{
	SetFontSize(26);
	DrawModiGraph(Define::GAME_WINDOW_X + Define::SCORE_WINDOW_X, 0, 0, 0, 0, Define::GAME_WINDOW_Y, Define::GAME_WINDOW_X + Define::SCORE_WINDOW_X, Define::GAME_WINDOW_Y, gameClearG, false);
	DrawString(50, 20, "ゲームクリア", GetColor(255, 255, 255), TRUE);
	DrawString(50, 100, "Zキーでタイトルに戻る", GetColor(255, 255, 255), TRUE);
	SetFontSize(16);
}
