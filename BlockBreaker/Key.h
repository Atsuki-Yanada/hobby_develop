#pragma once
class Key
{
private:
	static int keyUp, keyDown, keyLeft, keyRight, keyZ;
public:
	static void update();
	static int getKeyUp() { return keyUp; }
	static int getKeyDown() { return keyDown; }
	static int getKeyLeft() { return keyLeft; }
	static int getKeyRight() { return keyRight; }
	static int getKeyZ() { return keyZ; }
};

