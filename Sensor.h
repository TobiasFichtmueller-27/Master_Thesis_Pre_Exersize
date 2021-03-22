#pragma once
#include "World.h"
class Sensor
{
public:
	Sensor(World* world);
	int Get_Color();

private:
	World* world;
};

