#pragma once
#include<iostream>
#include<string>
using namespace std;

#include"draw.h"
#include"defines.h"

void draw_all(char* output_path, int steps, Map maps[]) {
	int step = 1;
	
	while (step < steps) {
		string step_str = output_path + (string)"/" +(string)"step"+to_string(step);
		char* outputname = (char*)step_str.data();
		draw_step(outputname, maps[step++]);
	}
}
