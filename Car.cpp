#include "Car.h"

//The car the steps of mooving and calculation come together
Car::Car(World* world, Navigation* navigation) {
	this->world = world;
	this->navigation = navigation;
}



void Car::Move() {
	this->navigation->Calculate_Position();
	world->Move_Car();
}

std::string Car::Get_Navigation_CSV() {
	const double *positions = navigation->Get_Position_Estimations();
	std::string tmp = "";
	for (int i = 0; i < world->Get_Size(); i++) {
		if (i > 0)
			tmp += ";";
		tmp += std::to_string(positions[i]);
	}

	return tmp;
}