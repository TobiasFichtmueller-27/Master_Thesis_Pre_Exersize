#pragma once
#include "World.h"
#include "Sensor.h"
class Navigation
{
public:
	
	Navigation(World* world, Sensor* sensor, double step_sccuracy, double sensor_accuracy);
	~Navigation();
	void Calculate_Position();
	const double* Get_Position_Estimations();

private: 
	World* world;
	Sensor* sensor;
	double* values;
	double step_accuracy;
	double sensor_accuracy;

};

