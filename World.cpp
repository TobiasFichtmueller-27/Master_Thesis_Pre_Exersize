#include "World.h"
#include <random>
#include <time.h>
#include <string>

World::World(int size, int ratio, int car_start_position) {


	this->size = size;
	this->fields = new int[size];
	this->car_position = car_start_position % size;

	//Basis for Random on current Timestamp
	srand(time(NULL));

	//Number of Orange fields according to the input
	int orange = ratio;
	//logic consequence for number of blue fields
	int blue = size - orange;
	int k;

	//Randomly distribution of blue and orange fields
	for (int i = 0; i < size; i++) {
		
		k=rand() % 2;
		
		if (k==1) {
			if (orange != 0)
				fields[i] = 1;

			else
				fields[i] = 0;
		}

		if (k!=1) {
			if (blue != 0)
				fields[i] = 0;
			else
				fields[i] = 1;
		}

		if (fields[i]==0)
			blue--;
		else
			orange--;
		
	}
}

//The program allways knows where the car is in reality. Here the position gets adjusted every step
void World::Move_Car() {
	this->car_position++;
	this->car_position = this->car_position % size;
}

int World::Get_Car_Position() {
	return this->car_position;
}

int World::Get_Position_Color() {
	return this->fields[car_position];
}


int World::Get_Color_At(int index) {
	return this->fields[index];
}

std::string World::Get_CSV() {
	std::string tmp = "";
	for (int i = 0; i < size; i++) {
		if (i > 0)
			tmp += ";";
		tmp += std::to_string(fields[i]);
	}

	return tmp;
}

World::~World() {
	delete[] this->fields;
}

int World::Get_Size() {
	return this->size;
}