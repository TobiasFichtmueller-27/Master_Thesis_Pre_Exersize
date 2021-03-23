#pragma once
#include <string>
class World
{
public:
	World(int size, int ratio, int car_start_position);
	~World();

	void Move_Car();
	int Get_Size();
	int Get_Car_Position();
	int Get_Position_Color();
	int Get_Color_At(int index);
	std::string Get_CSV();

private: 
	int size;
	int* fields;
	int car_position;
};

