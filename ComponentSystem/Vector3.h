#pragma once

#include <string>

using namespace std;

class Vector3
{
public:
	Vector3()
	{

	}

	~Vector3()
	{

	}

	Vector3(float x, float y, float z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	inline float getX() { return m_x; }
	inline float getY() { return m_y; }
	inline float getZ() { return m_z; }

	inline std::string toString()
	{
		char* buffer = new char[100];
		sprintf_s(buffer, 100, "(%f, %f, %f)", m_x, m_y, m_z);
		
		return buffer;
	}

private:
	float m_x = 0;
	float m_y = 0;
	float m_z = 0;
};