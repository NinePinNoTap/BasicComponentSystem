#pragma once

#include <typeinfo>
#include <unordered_map>

#include "Component.h"

using namespace std;

class Entity
{
public:
	Entity() { }
	~Entity() { }

	// Description:
	// Function to add a component to the entity
	template <typename T>
	void addComponent()
	{
		components[&typeid(T)] = new T;

		return;
	}

	// Description:
	// Function to add a component to the entity and return it
	template <typename T>
	void addComponent(T** component)
	{
		*component = new T;
		components[&typeid(T)] = *component;

		return;
	}

	// Description:
	// Function to get a component from the entity
	template <typename T>
	T*	getComponent()
	{
		if (components.count(&typeid(T)) != 0)
		{
			return static_cast<T*>(components[&typeid(T)]);
		}

		return nullptr;
	}
	template <typename T>
	void getComponent(Component** component)
	{
		if (components.count(&typeid(T)) != 0)
		{
			*component = static_cast<T*>(components[&typeid(T)]);
			return;
		}

		*component = nullptr;
	}

	// Description:
	// Function to check if the entity has the component
	template <typename T>
	bool hasComponent()
	{
		T* component = getComponent<T>();

		return component != nullptr;
	}

private:
	std::unordered_map<const std::type_info*, Component *> components;
};