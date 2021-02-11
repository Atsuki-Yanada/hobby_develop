#include "GameOverScene.h"
#include "ISceneChangedListener.h"
#include "Dxlib.h"
#include "Key.h"
#include "Define.h"


GameOverScene::GameOverScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	gameOverG = LoadGraph("LoadFile\\Graph\\gameover.jpg");
}


GameOverScene::~GameOverScene()
{
}

void GameOverScene::update()
{
	if (Key::getKeyZ() == 1) {
		nScene::Message message;
		_mgr->changeScene(nScene::Title, message);
		return;
	}
}

void GameOverScene::draw() const
{
	SetFontSize(26);
	DrawModiGraph(Define::GAME_WINDOW_X + Define::SCORE_WINDOW_X, 0, 0, 0, 0, Define::GAME_WINDOW_Y, Define::GAME_WINDOW_X + Define::SCORE_WINDOW_X, Define::GAME_WINDOW_Y, gameOverG, false);
	DrawString(50, 20, "ゲームオーバー", GetColor(255, 255, 255), TRUE);
	DrawString(50, 100, "Zキーでタイトルに戻る", GetColor(255, 255, 255), TRUE);
	SetFontSize(16);
}
