#include "Error.h"
#include "Key.h"
#include<DxLib.h>

using namespace std;


Error::Error()
{
}


Error::~Error()
{
}

void Error::err(const std::string &str)
{
	while (!ProcessMessage()) {
		//Key::update();
		ClearDrawScreen();
		ScreenFlip();
		clsDx();

		printfDx(str.c_str());
	}
}
