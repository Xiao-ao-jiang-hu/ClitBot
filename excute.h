#pragma once 

#include<iostream>
#include<string.h>
#include"defines.h"
using namespace std;


Map step(Map pre, int op) {
	//单步操作函数
	//op:  1:=TL;2:=TR; 3:=MOV; 4:JMP; 5:=LIT;  6:=P1; 7:=P2;
	//输入：一个地图初始状态，一个指令；   输出：完成一个指令后的地图状态
	if (op == 1) {//左转
		if (pre.robot.direction == 1)
			pre.robot.direction = 2;
		else if (pre.robot.direction == 2)
			pre.robot.direction = 3;
		else if (pre.robot.direction == 3)
			pre.robot.direction = 4;
		else if (pre.robot.direction == 4)
			pre.robot.direction = 1;
	}
	else if (op == 2) {//右转
		if (pre.robot.direction == 2)
			pre.robot.direction = 1;
		else if (pre.robot.direction == 3)
			pre.robot.direction = 2;
		else if (pre.robot.direction == 4)
			pre.robot.direction = 3;
		else if (pre.robot.direction == 1)
			pre.robot.direction = 4;
	}
	else if (op == 3) {//前方高度一致时前进
		if (pre.robot.direction == 1 && pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			== pre.cells[pre.robot.pos.x][pre.robot.pos.y - 1].height) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.y -= 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}
		else if (pre.robot.direction == 2 && pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			== pre.cells[pre.robot.pos.x - 1][pre.robot.pos.y].height) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.x -= 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}
		else if (pre.robot.direction == 3 && pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			== pre.cells[pre.robot.pos.x][pre.robot.pos.y + 1].height) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.y += 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}
		else if (pre.robot.direction == 4 && pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			== pre.cells[pre.robot.pos.x + 1][pre.robot.pos.y].height) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.x += 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}
	}
	else if (op == 4) {//跳跃
		if (pre.robot.direction == 1 && ((pre.cells[pre.robot.pos.x][pre.robot.pos.y - 1].height) > 0)
			&& ((pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			> pre.cells[pre.robot.pos.x][pre.robot.pos.y - 1].height) ||
				(pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
					== pre.cells[pre.robot.pos.x][pre.robot.pos.y - 1].height - 1))) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.y -= 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}

		else if (pre.robot.direction == 2 && ((pre.cells[pre.robot.pos.x - 1][pre.robot.pos.y].height) > 0)
			&& ((pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			> pre.cells[pre.robot.pos.x - 1][pre.robot.pos.y].height) ||
				(pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
					== pre.cells[pre.robot.pos.x - 1][pre.robot.pos.y].height - 1))) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.x -= 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}

		else if (pre.robot.direction == 3 && ((pre.cells[pre.robot.pos.x][pre.robot.pos.y + 1].height) > 0)
			&& ((pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			> pre.cells[pre.robot.pos.x][pre.robot.pos.y + 1].height) ||
				(pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
					== pre.cells[pre.robot.pos.x][pre.robot.pos.y + 1].height - 1))) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.y += 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}

		else if (pre.robot.direction == 4 && ((pre.cells[pre.robot.pos.x + 1][pre.robot.pos.y].height) > 0)
			&& ((pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
			> pre.cells[pre.robot.pos.x + 1][pre.robot.pos.y].height) ||
				(pre.cells[pre.robot.pos.x][pre.robot.pos.y].height
					== pre.cells[pre.robot.pos.x + 1][pre.robot.pos.y].height - 1))) {
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 0;
			pre.robot.pos.x += 1;
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].robot = 1;
		}

	}
	else if (op == 5) {//灯灭点亮，灯亮不变
		if (pre.cells[pre.robot.pos.x][pre.robot.pos.y].light == 1)
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].light = 2;
		pre.num_lights++;//灯亮的总数
	}
	return pre;
}

Map stepmap[30];//存储每一步的地图状态
int lightnumber;
int excute(Map map0, int a, int b, int c, int d, int* arr1, int* arr2, int* arr3, int*arr4) {
	//连续执行函数
	//分别传入初始地图状态；操作主函数，P1，P2的操作数（a,b,c) 及对应的操作过程(数组1,2,3)
	//只能在主程序中调用子程序
	stepmap[0] = map0; //第0位是传入时的初始状态

	lightnumber = 0;
	//灯的总数
	for (int i = 0; i < map0.row; i++) {
		for (int j = 0; j < map0.col; j++) {
			if (map0.cells[i][j].light == 1) {
				lightnumber++;
			}
		}
	}

	int p = 1;  //输出地图状态应是1到p-1位
	for (int i = 0; i < a; i++) {
		if (stepmap[p - 1].num_lights == lightnumber) {
			break;
		}
		if (arr1[i] >= 1 && arr1[i] <= 5) {
			stepmap[p] = step(stepmap[p - 1], arr1[i]);
			p++;
		}
		else if (arr1[i] == 6) {//进入P1
			for (int j = 0; j < b; j++) {
				stepmap[p] = step(stepmap[p - 1], arr2[j]);
				p++;
			}
		}
		else if (arr1[i] == 7) {//进入P2
			for (int k = 0; k < c; k++) {
				stepmap[p] = step(stepmap[p - 1], arr3[k]);
				p++;
			}
		}
		else if (arr1[i] == 8) {//进入P3
			for (int k = 0; k < d; k++) {
				stepmap[p] = step(stepmap[p - 1], arr4[k]);
				p++;
			}
		}

	}
	return p - 1;

}
