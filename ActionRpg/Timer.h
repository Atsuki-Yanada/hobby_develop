#pragma once

#include<stack>
#include<string>
#include<map>
#include"DxLib.h"
#include<iostream>

//“Á’è‹æŠÔ‚ÌŠÔ‚ğ}‚é
//’PˆÊ‚Íƒ~ƒŠ•b
class Timer
{
public:
	class Timestamp {
	public:
		Timestamp() : _s(LARGE_INTEGER()), _e(LARGE_INTEGER()) {}
		explicit Timestamp(LARGE_INTEGER s) : _s(s), _e(LARGE_INTEGER()) {}
		LARGE_INTEGER _s, _e;
	};
private:
	std::stack<Timestamp> _timestamps;
	std::map<std::string, Timestamp> _mTimestamps;

	LARGE_INTEGER _frequency;
public:
	Timer();

	void start();
	float stop();

	void start(const std::string&);
	float stop(const std::string&);

};
