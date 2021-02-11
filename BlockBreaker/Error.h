#pragma once
#include<string>

class Error
{
public:
	Error();
	~Error();
	static void err(const std::string&);
};

