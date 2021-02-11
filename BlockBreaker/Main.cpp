#include"Looper.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hp, LPSTR lpC, int nC) {
	Looper looper;
	looper.initialize();
	looper.process();
	return 0;
}