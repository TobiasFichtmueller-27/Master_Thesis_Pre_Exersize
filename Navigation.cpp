#include "Navigation.h"
#include <stdio.h>
#include <iostream>



Navigation::Navigation(World* world,Sensor *sensor,double step_accuracy, double sensor_accuracy) {
	this->world = world;
	this->sensor = sensor;
	this->step_accuracy = step_accuracy;
	this->sensor_accuracy = sensor_accuracy;
	this->values = new double[world->Get_Size()];

	std::cout <<"SA"<< step_accuracy;
	std::cout << "SE" << sensor_accuracy;
	std::cout << "test" << (1 - step_accuracy) / 2;

	for (int i = 0; i < world->Get_Size(); i++)
	{
		values[i] = 1 / (double)world->Get_Size();
	}
}

Navigation::~Navigation() {
	delete[] values;
}

void Navigation::Calculate_Position() {

    
	double* tmp = new double[world->Get_Size()];
	for (int i = 0; i < world->Get_Size(); i++)
	{
		tmp[i] = values[i] * ((1-step_accuracy)/2);
		tmp[i] += values[(i - 1 + world->Get_Size()) % world->Get_Size()] * step_accuracy;
		tmp[i] += values[(i - 2 + world->Get_Size()) % world->Get_Size()] * ((1 - step_accuracy) / 2);
	}

	double sum = 0;
	for (int i = 0; i < world->Get_Size(); i++)
	{
		if (world->Get_Color_At(i) == sensor->Get_Color())
			tmp[i] = tmp[i] * sensor_accuracy;
		else
			tmp[i] = tmp[i] * (1-sensor_accuracy);

		sum += tmp[i];
	}

	for (int i = 0; i < world->Get_Size(); i++)
	{
		tmp[i] = tmp[i] / sum;
	}

	delete[]this->values;
	this->values = tmp;

}

const double* Navigation::Get_Position_Estimations() {
	return this->values;
}
