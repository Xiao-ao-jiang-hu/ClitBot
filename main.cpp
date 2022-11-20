using namespace std;
//#include<Python.h>
#include"draw.h"
#include"show.h"

const int MAX_ROW = 4;
const int MAX_COL = 5;
const int MAX_LIT = 10;
const int MAX_PROCS = 30;



Cell cell[2][3] = { {{2,0,0} ,{2,0,0}} ,{{2,0,0} ,{2,0,0}} };

Map map0;

int main() {
	char savepath[] = "outputs/output.bmp";
	char filename[] = "outputs/output.bmp";
	draw_step(savepath, map0);

	show(filename);
}
