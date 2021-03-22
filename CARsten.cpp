// CARsten.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "World.h"
#include "Sensor.h"
#include "Car.h"
#include "Navigation.h"
int main()
{
	World* world = new World(5, 3);
	Sensor* sensor = new Sensor(world);
	Navigation* navigation = new Navigation(world, sensor, 0.9, 0.9);
	Car* car = new Car(world, navigation);
	int steps = 12;
	std::ofstream myfile;
	myfile.open("histogramm.csv");

	myfile << world->Get_CSV() << "\n";
	for (int i = 0; i < steps; i++)
	{
		std::cout << "\n";
		car->Move();
		myfile << car->Get_Navigation_CSV() << "\n";
	}

	myfile.close();
}
