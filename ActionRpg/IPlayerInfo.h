#pragma once
#include<memory>

class Player;

class IPlayerInfo {
public:
	virtual std::shared_ptr<Player> getPlayer() = 0;
	virtual ~IPlayerInfo() = default;
};