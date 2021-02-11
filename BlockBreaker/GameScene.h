#pragma once
#include "AbstractScene.h"
#include <memory>

class Player;
class Tama;
class Block_Mgr;
class Star_Mgr;
class Collision;
class Score;
class Time;
class Combo;

class GameScene final : public AbstractScene
{
private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Tama> tama;
	std::shared_ptr<Block_Mgr> block_mgr;
	std::shared_ptr<Star_Mgr> star_mgr;
	std::shared_ptr<Collision> collision;
	std::shared_ptr<Score> score;
	std::shared_ptr<Time> time;
	std::shared_ptr<Combo> combo;
	int earthG;
	int gameS;
	int gameClearS;
	int gameOverS;
public:
	explicit GameScene(ISceneChangedListener* const mgr, const nScene::Message&);
	~GameScene();
	void update()override;
	void draw()const override;
	void debugDraw()override;
};

