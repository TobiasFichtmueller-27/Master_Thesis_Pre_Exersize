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

	//World(size, of which orange, start position of car) When creating a World one can adjust here the size of the World and the ratio of blue and orange fields by typing in the total of the orange fields and at last the position from where the car starts
	
	World* world = new World(10, 2, 0);

	//The simulated sensor, that knows where the car is an then "sensores" the associated color
	Sensor* sensor = new Sensor(world);

	//Calculation of the Histogram Filter: Navigation(wold, sensor, accuracy of the steps, accuracy of the sensor)
	Navigation* navigation = new Navigation(world, sensor, 0.9, 0.9);

	//Class to handle the position and next steps
	Car* car = new Car(world, navigation);

	//Number of steps that should be executed
	int steps = 12;

	//Extraction in csv file
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
