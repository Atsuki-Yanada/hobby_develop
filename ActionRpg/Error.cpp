#include "Error.h"
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
	clsDx();
	printfDx(str.c_str());
	while (!ProcessMessage()) {
		//Key::update();
		ClearDrawScreen();
		ScreenFlip();
	}
}
