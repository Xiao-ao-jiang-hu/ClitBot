#include<iostream>
#include<fstream>
#include"defines.h"
using namespace std;


Map Load(char* name) {
	int arr[50]{};
	int datalen = 0;
	ifstream file(name);
	while (!file.eof())
		file >> arr[datalen++];
	Map map_init;
	int proc_num_limit;
	map_init.row = arr[0];
	map_init.col = arr[1];
	map_init.num_lights = arr[2];
	proc_num_limit = arr[3];

	int row = map_init.row;
	int col = map_init.col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map_init.cells[i][j].height = arr[i * col + j + 4];
		}
	}

	for (int i = 0; i < map_init.num_lights; i++) {
		map_init.lights[i].pos.y = arr[col * row + 4 + 2 * i];
		map_init.lights[i].pos.x = arr[col * row + 5 + 2 * i];
		map_init.cells[map_init.lights[i].pos.x][map_init.lights[i].pos.y].light = 1;
		map_init.lights[i].lighten = 0;//³õÊ¼»¯ ×´Ì¬ÎªÃð   
	}
	for (int i = 0; i < proc_num_limit; i++) {
		map_init.op_limit[i] = arr[col * row + 2 * map_init.num_lights + 4 + i];
	}
	map_init.robot.pos.y = arr[col * row + 2 * map_init.num_lights + proc_num_limit + 4];
	map_init.robot.pos.x = arr[col * row + 2 * map_init.num_lights + proc_num_limit + 5];
	map_init.robot.direction = arr[col * row + 2 * map_init.num_lights + proc_num_limit + 6];
	map_init.cells[map_init.robot.pos.x][map_init.robot.pos.y].robot = 1;
	if (map_init.robot.direction == 2) {
		map_init.robot.direction = 1;
	}
	else if (map_init.robot.direction == 1) {
		map_init.robot.direction = 1;
	}
	else if (map_init.robot.direction == 3) {
		map_init.robot.direction = 4;
	}
	else {
		map_init.robot.direction = 3;
	}
	map_init.num_lights = 0;

	return map_init;
};
