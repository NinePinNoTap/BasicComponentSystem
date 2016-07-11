#pragma once

#include "Component.h"
#include "Vector3.h"

class Transform : public Component
{
public:
	Transform() { }
	~Transform() { }

	inline void setPosition(Vector3 position) { m_position = position; }
	inline void setRotation(Vector3 rotation) { m_rotation = rotation; }
	inline void setScale(Vector3 scale)		  { m_scale = scale; }

	inline Vector3 getPosition() { return m_position; }
	inline Vector3 getRotation() { return m_rotation; }
	inline Vector3 getScale()	 { return m_scale; }

	inline virtual std::string toString()
	{
		std::string output = ("\n\tPosition : " + m_position.toString()
			+ "\n\tRotation : " + m_rotation.toString()
			+ "\n\tScale : " + m_scale.toString());

		return output;
	}

private:
	Vector3		m_position		= Vector3(0, 0, 0);
	Vector3		m_rotation		= Vector3(0, 0, 0);
	Vector3		m_scale			= Vector3(1, 1, 1);
};