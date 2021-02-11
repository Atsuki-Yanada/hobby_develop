#include "Key.h"
#include "DxLib.h"

bool Key::update()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);

	for (int i = 0; i < KEY_NUM; ++i) {
		if (nowKeyStatus[i] != 0) {
			if (_releasingCnt[i] > 0) _releasingCnt[i] = 0;
			_pressingCnt[i]++;
		}
		else {
			if (_pressingCnt[i] > 0) _pressingCnt[i] = 0;
			_releasingCnt[i]++;
		}
	}
	return true;
}

int Key::getPressingCnt(int keyCode)
{
	if (!isAvailableCode(keyCode)) return -1;
	return _pressingCnt[keyCode];
}

int Key::getReleasingCnt(int keyCode)
{
	if (!isAvailableCode(keyCode)) return -1;
	return _releasingCnt[keyCode];
}

bool Key::isAvailableCode(int keyCode)
{
	if(!(0 <= keyCode && keyCode < KEY_NUM)) return false;
	return true;
}