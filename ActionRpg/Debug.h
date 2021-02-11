#pragma once
#include<sstream>
#include<string>
#include<vector>

class Debug
{
private:
	static std::stringstream _ss;

	static int _debugStrX, _debugStrY;
public:
	//����������W���w�肵�ĕ\��
	static void drawStringWidthCoord(int, int, std::string);

	//�f�o�b�O�p�̕������\���J�n������W���w��
	static void setCoordDebugString(int, int);

	//������������\��
	static void drawString(std::string);

	//�t�H�[�}�b�g�w��q���g���ĕ���������
	template<typename ...Args>
	static std::string format(const std::string& fmt, Args... args) {
		size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args...);
		std::vector<char> buf(len + 1);
		std::snprintf(&buf[0], len + 1, fmt.c_str(), args...);
		return std::string(&buf[0], &buf[0] + len);
	}

	//���ۂɃf�o�b�O�\��������
	static void draw();
};

