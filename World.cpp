#include "World.h"
#include <random>
#include <time.h>
#include <string>

World::World(int size, int ratio) {
	this->size = size;
	this->fields = new int[size];
	this->car_position = 0;

	srand(time(NULL));
	int orange = ratio;
	int blue = size - orange;
	int k;

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