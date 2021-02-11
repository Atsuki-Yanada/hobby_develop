#pragma once

class Looper
{
private:
	int looperS;
public:
	Looper();
	~Looper();
	void process();
	bool initialize();
};

