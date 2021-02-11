#include "GameScene.h"
#include "ISceneChangedListener.h"
#include "Key.h"
#include "Player.h"
#include "Block_Mgr.h"
#include "Tama.h"
#include "Star_Mgr.h"
#include "Collision.h"
#include "Score.h"
#include "Time.h"
#include "Combo.h"
#include "DxLib.h"
#include "Define.h"
#include "Error.h"

using namespace std;
GameScene::GameScene(ISceneChangedListener* const mgr, const nScene::Message& message) : AbstractScene(mgr, message)
{
	player = make_shared<Player>();
	tama = make_shared<Tama>(); 

	nBlockMgr::Message mes;
	mes._stageNum = message._stageNum;
	block_mgr =	make_shared<Block_Mgr>(mes);

	star_mgr = make_shared<Star_Mgr>();
	collision =	make_shared<Collision>();
	score =	make_shared<Score>();
	time = make_shared<Time>();
	combo =	make_shared<Combo>();
	gameS = LoadSoundMem("LoadFile\\Sound\\digitalworld.wav");
	PlaySoundMem(gameS, DX_PLAYTYPE_LOOP);
	earthG = LoadGraph("LoadFile\\Graph\\earth.jpg");
	gameClearS = LoadSoundMem("LoadFile\\Sound\\gameclear_se.mp3");
	gameOverS = LoadSoundMem("LoadFile\\Sound\\gameover_se.mp3");
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	star_mgr->update();
	player->update();
	//player->update(tama);
	tama->update();
	tama->put(*player);
	block_mgr->update(&(*tama), &(*combo), &(*score));
	collision->updatePT(*player, *tama, *combo);
	time->update();
	if (!block_mgr->getBlockExist()) {
		StopSoundMem(gameS);
		PlaySoundMem(gameClearS, DX_PLAYTYPE_BACK);
		nScene::Message message;
		_mgr->changeScene(nScene::GameClear, message);
		return;
	}
	if (!tama->getTamaRemainExsit()) {
		StopSoundMem(gameS);
		PlaySoundMem(gameOverS, DX_PLAYTYPE_BACK);
		nScene::Message message;
		_mgr->changeScene(nScene::GameOver, message);
		return;
	}
}

void GameScene::draw()const
{
	DrawModiGraph(Define::GAME_WINDOW_X, 0, 0, 0, 0, Define::GAME_WINDOW_Y, Define::GAME_WINDOW_X, Define::GAME_WINDOW_Y, earthG, false);
	//DrawBox(0, 0, Define::GAME_WINDOW_X, Define::GAME_WINDOW_Y, GetColor(0, 0, 0), TRUE);
	star_mgr->draw();
	player->draw();
	tama->draw();
	block_mgr->draw();
	score->draw(*tama);
	time->draw();
	combo->draw();
}

void GameScene::debugDraw()
{
	block_mgr->debugDraw();
}
