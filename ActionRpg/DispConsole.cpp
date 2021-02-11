#include"DispConsole.h"

void DispConsole() {
	//コンソールを作成する
	AllocConsole();
	FILE* fp = NULL;

	//標準入出力先をコンソールへ変更
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONIN$", "r", stdin);
}