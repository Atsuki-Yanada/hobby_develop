#pragma once

class Scene;

class Time
{
private:
	int nowTime;
	int initTime;
	int resultTime;
	bool initFlag;
public:
	Time();
	~Time();
	static const int LIMIT_TIME;
	void update();
	void draw()const;
};

