#pragma once
#include "World.h"
#include "Navigation.h"
#include <string>
class Car
{
public:
	Car(World* world, Navigation *navigation);
	void Move();
	std::string Get_Navigation_CSV();

private:
	World* world;
	Navigation* navigation;
};

