#pragma once
using namespace std;
//#include<Python.h>
#include"draw_all.h"
#include"draw.h"
#include"show.h"
#include"defines.h"
#include"excute.h"

const int MAX_ROW = 4;
const int MAX_COL = 5;
const int MAX_LIT = 10;
const int MAX_PROCS = 30;


int run_draw(Map map0, int* arr1, int* arr2, int* arr3, int* arr4, int i, int j, int k, int l) {

	char a[] = "outputs";

	/*
	arr1[0] = 3;
	arr1[1] = 3;
	arr1[2] = 1;
	arr1[3] = 4;
	arr1[4] = 2;
	arr1[5] = 6;
	arr1[6] = 7;
	arr1[7] = 5;

	arr2[0] = 3;
	arr2[1] = 5;
	arr2[2] = 4;
	*/

	int show_num = excute(map0, i, j, k,l, arr1, arr2, arr3,arr4);
	draw_all(a, show_num+1, stepmap);
	return show_num;
}
