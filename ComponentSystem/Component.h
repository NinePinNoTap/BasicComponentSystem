#pragma once

#include <string>

using namespace std;

class Component
{
public:
	virtual void terminate()
	{
	}

	virtual std::string toString() = 0;
};