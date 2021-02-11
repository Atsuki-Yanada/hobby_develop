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
	//文字列を座標を指定して表示
	static void drawStringWidthCoord(int, int, std::string);

	//デバッグ用の文字列を表示開始する座標を指定
	static void setCoordDebugString(int, int);

	//文字列を順次表示
	static void drawString(std::string);

	//フォーマット指定子を使って文字列を作る
	template<typename ...Args>
	static std::string format(const std::string& fmt, Args... args) {
		size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args...);
		std::vector<char> buf(len + 1);
		std::snprintf(&buf[0], len + 1, fmt.c_str(), args...);
		return std::string(&buf[0], &buf[0] + len);
	}

	//実際にデバッグ表示をする
	static void draw();
};

