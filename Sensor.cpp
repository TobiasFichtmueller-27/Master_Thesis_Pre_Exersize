#include "Sensor.h"
//In this case the sensor gets his "data" from the program its self by the class world where the position if the car is known and therefor the colour that the sensor should measure
Sensor::Sensor(World* world) {
	this->world = world;
}

int Sensor::Get_Color() {
	return this->world->Get_Position_Color();
}