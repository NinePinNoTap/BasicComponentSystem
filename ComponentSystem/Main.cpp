#include <iostream>
#include <string>

#include"Entity.h"
#include "Transform.h"

using namespace std;

void main()
{
	Entity* entity;
	Transform* transform;

	// Create Entity
	entity = new Entity;

	// Component checks
	printf("Check One!\n");
	if (entity->hasComponent<Transform>())
	{
		printf("Entity has component");
	}
	else
	{
		printf("Entity does not have component");
	}

	printf("\n\nCheck Two!\n");
	entity->addComponent<Transform>(&transform);

	if (transform)
	{
		string temp = transform->toString();
		printf("Transform : \n%s", temp.c_str());
	}
	else
	{
		printf("Transform is null");
	}

	printf("\n\nCheck Three!\n");

	if (entity->hasComponent<Transform>())
	{
		printf("Transform was found");
	}
	else
	{
		printf("Transform was not found");
	}
	cin.get();
}