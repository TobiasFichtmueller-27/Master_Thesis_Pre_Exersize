#include "Sensor.h"

Sensor::Sensor(World* world) {
	this->world = world;
}

int Sensor::Get_Color() {
	return this->world->Get_Position_Color();
}