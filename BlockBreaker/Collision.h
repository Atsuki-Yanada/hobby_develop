#pragma once
#include <memory>

class Player;
class Tama;
class Block;
class Block_Mgr;
class Score;
class Combo;

class Collision
{
public:
	Collision();
	~Collision();
	void updatePT(const Player&,Tama&, Combo&);
	void updateTB(Tama*, std::shared_ptr<Block>, Combo*, Score*);
};