#include"DispConsole.h"

void DispConsole() {
	//�R���\�[�����쐬����
	AllocConsole();
	FILE* fp = NULL;

	//�W�����o�͐���R���\�[���֕ύX
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONIN$", "r", stdin);
}