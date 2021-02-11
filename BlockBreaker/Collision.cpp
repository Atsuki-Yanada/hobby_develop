#include "Collision.h"
#include "Player.h"
#include "Tama.h"
#include "Block.h"
#include "Block_Mgr.h"
#include "Score.h"
#include "Combo.h"
#include <math.h>

Collision::Collision()
{
}


Collision::~Collision()
{
}

void Collision::updatePT(const Player& player,Tama& tama, Combo& combo) {
	if (abs(player.getX() - tama.getX()) <= player.GetLength() / 2 + tama.getRange())
	{
		if (tama.getY() + tama.getRange() >= player.getY() && tama.getY() - tama.getRange() <= player.getY() + player.GetHegiht())
		{
			tama.CollisionMessagePT();
			tama.ChangeVelocity();
			combo.zero();
		}
		else tama.NotCollsionMessagePT();
	}
	else tama.NotCollsionMessagePT();
}

void Collision::updateTB( Tama* tama, std::shared_ptr<Block> block, Combo *combo, Score *score)
{
	
	if (tama->getX() >= block->getX() && tama->getX() <= block->getX() + block->getLength()) {
		if (tama->getY() + tama->getRange() >= block->getY() && tama->getY() + tama->getRange() <= block->getY() + 10){
			if (tama->getVy() > 0) {
				tama->CollisionMessageUD();
				block->collisionMessage();
				combo->plus();
				score->update(combo->getCombo());
			}
		}
		if (tama->getY() - tama->getRange() <= block->getY() + block->getHeight() && tama->getY() - tama->getRange() >= block->getY() + block->getHeight() - 10) {
			if (tama->getVy() < 0) {
				tama->CollisionMessageUD();
				block->collisionMessage();
				combo->plus();
				score->update(combo->getCombo());
			}
		}
	}
	if (tama->getY() <= block->getY() + block->getHeight() && tama->getY() >= block->getY()) {
		if (tama->getX() - tama->getRange() <= block->getX() + block->getLength() && tama->getX() - tama->getRange() >= block->getX() + block->getLength() - 10) {//   <@‚©‚ç ==
			if (tama->getVx() < 0) {
				tama->CollisionMessageLR();
				block->collisionMessage();
				combo->plus();
				score->update(combo->getCombo());
			}
		}
		if (tama->getX() + tama->getRange() >= block->getX() && tama->getX() + tama->getRange() <= block->getX() + 10) {//@ >  ‚©‚ç ==
			if (tama->getVx() > 0) {
				tama->CollisionMessageLR();
				block->collisionMessage();
				combo->plus();
				score->update(combo->getCombo());
			}
		}
	}
}