using namespace std;
//#include<Python.h>
#include"draw_all.h"
#include"draw.h"
#include"show.h"
#include"defines.h"

const int MAX_ROW = 4;
const int MAX_COL = 5;
const int MAX_LIT = 10;
const int MAX_PROCS = 30;




Map map0;

int main() {
	int a;
	cin >> a;
	char savepath[] = "outputs/output.bmp";
	char filename[] = "resources/background.bmp";
	draw_step(savepath, map0);

	show(savepath);
	show(filename);
}
