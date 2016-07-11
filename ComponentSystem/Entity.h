#pragma once

#include <typeinfo>
#include <unordered_map>
#include <assert.h>

#include "Component.h"

using namespace std;

class Entity
{
public:
	Entity() { }
	~Entity() { }

#pragma region EntityComponentManagement
	// Description:
	// Function to add a component to the entity
	template <typename T>
	void addComponent()
	{
		assert(std::is_base_of<Component, T>());
		assert(!hasComponent<T>());

		m_components[&typeid(T)] = new T;

		return;
	}

	// Description:
	// Function to add a component to the entity and return it
	template <typename T>
	void addComponent(T** component)
	{
		assert(std::is_base_of<Component, T>());
		assert(!hasComponent<T>());

		*component = new T;
		m_components[&typeid(T)] = *component;

		return;
	}

	// Description:
	// Function to get a component from the entity
	template <typename T>
	T*	getComponent() const 
	{
		assert(std::is_base_of<Component, T>());

		if (m_components.count(&typeid(T)) != 0)
		{
			return static_cast<T*>(m_components[&typeid(T)]);
		}

		return nullptr;
	}

	template <typename T>
	void getComponent(Component** component) const
	{
		assert(std::is_base_of<Component, T>());
		
		if (m_components.count(&typeid(T)) != 0)
		{
			*component = static_cast<T*>(m_components[&typeid(T)]);
			return;
		}

		*component = nullptr;
	}

	// Description:
	// Function to check if the entity has the component
	template <typename T>
	bool hasComponent() const 
	{
		T* component = getComponent<T>();

		return component != nullptr;
	}

	// Description:
	// Function to remove a component from entity
	template <typename T>
	bool removeComponent()
	{
		component_it = m_components.find(&typeid(T));

		if (component_it != m_components.end())
		{
			if (component_it->second)
			{
				component_it->second->terminate();
				delete component_it->second;
			}

			m_components.erase(component_it);

			return true;
		}

		return false;
	}

	// Description:
	// Function to remove all components from entity
	void removeAllComponents()
	{
		for (component_it = m_components.begin(); component_it != m_components.end())
		{
			if (component_it->second)
			{
				component_it->second->terminate();
				delete component_it->second;
			}
		}
		
		m_components.clear();
	}

#pragma endregion

private:
	int objectID = 0;
	std::string name = "Not Set";

	std::unordered_map<const std::type_info*, Component *> m_components;
	std::unordered_map<const std::type_info*, Component *>::iterator component_it;
};