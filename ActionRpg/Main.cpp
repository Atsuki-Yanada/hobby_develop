#include "Looper.h"
#include "DxLib.h"
#include<exception>

using namespace std;

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hp, LPSTR lpC, int nC) {
	try {
		Looper looper;
		looper.initialize();
		looper.process();
	}
	catch (const exception& e) {
		MessageBox(NULL, e.what(), "ERROR", MB_OK);
		abort();
	}
	return 0;
}