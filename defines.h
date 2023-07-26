//通用数据结构
#pragma once

struct Position {
	int x, y; // x 表示列号，y 表示行号 
};

struct Robot {
	Position pos; // 机器人位置 
	int direction; // 机器人朝向，1前，2左，3下，4右
};

struct Cell {
	int height=0; // 高度 
	int light=0;//灯状态，0代表没有灯，1代表有灯没点亮，2代表有灯且点亮
	bool robot=0;//单元格上是否有机器人
};

// 灯类型
struct Light {
	Position pos; // 灯位置
	bool lighten; // 是否被点亮
};

struct Map {
	// 单元格组成二维数组，MAX_ROW、MAX_COL为合理常数 
	Cell cells[6][8];
	// 有效行数、有效列数
	int row, col;
	// 灯记录，MAX_LIT为合理常数
	Light lights[50];
	//已经点亮的灯的数目
	int num_lights = 0;
	Robot robot;
	// 每个过程的指令数限制
	int op_limit[4] = { 0,0,0,0 };
};
