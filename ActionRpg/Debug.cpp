#include "Debug.h"
#include"DxLib.h"

using namespace std;


std::stringstream Debug::_ss;

int Debug::_debugStrX = 800, Debug::_debugStrY = 100;

void Debug::drawStringWidthCoord(int x, int y, std::string str)
{
	DrawString(x, y, str.c_str(), GetColor(255, 255, 255), GetColor(0, 0, 0));
}

void Debug::setCoordDebugString(int x, int y)
{
	_debugStrX = x;
	_debugStrY = y;
}

void Debug::drawString(std::string str)
{
	_ss << str;
}

void Debug::draw()
{
	DrawString(_debugStrX, _debugStrY, _ss.str().c_str(), GetColor(255, 255, 255), GetColor(0, 0, 0));

	_ss.str("");
	_ss.clear(stringstream::goodbit);
}
