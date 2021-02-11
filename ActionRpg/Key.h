#pragma once
#include "Singleton.h"
#include <array>

class Key final : public Singleton<Key>
{
private :
	Key() = default;
	friend Singleton<Key>;

	static const int KEY_NUM = 256;
	std::array<int, KEY_NUM> _pressingCnt;
	std::array<int, KEY_NUM> _releasingCnt;

	bool isAvailableCode(int keyCode);
public :
	bool update();
	int getPressingCnt(int keyCode);
	int getReleasingCnt(int keyCode);
};

