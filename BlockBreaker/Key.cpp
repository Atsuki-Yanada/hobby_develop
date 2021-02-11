#include "Key.h"
#include "DxLib.h"

int Key::keyUp;
int Key::keyDown;
int Key::keyLeft;
int Key::keyRight;
int Key::keyZ;
void Key::update()
{
	if (CheckHitKey(KEY_INPUT_UP) != 0) keyUp++;
	else keyUp = 0;
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) keyDown++;
	else keyDown = 0;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) keyLeft++;
	else keyLeft = 0;
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) keyRight++;
	else keyRight = 0;
	if (CheckHitKey(KEY_INPUT_Z) != 0) keyZ++;
	else keyZ = 0;
}
