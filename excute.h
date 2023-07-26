#pragma once 

#include<iostream>
#include<string.h>
#include"defines.h"
using namespace std;


Map step(Map pre, int op) {
	//������������
	//op:  1:=TL;2:=TR; 3:=MOV; 4:JMP; 5:=LIT;  6:=P1; 7:=P2;
	//���룺һ����ͼ��ʼ״̬��һ��ָ�   ��������һ��ָ���ĵ�ͼ״̬
	if (op == 1) {//��ת
		if (pre.robot.direction == 1)
			pre.robot.direction = 2;
		else if (pre.robot.direction == 2)
			pre.robot.direction = 3;
		else if (pre.robot.direction == 3)
			pre.robot.direction = 4;
		else if (pre.robot.direction == 4)
			pre.robot.direction = 1;
	}
	else if (op == 2) {//��ת
		if (pre.robot.direction == 2)
			pre.robot.direction = 1;
		else if (pre.robot.direction == 3)
			pre.robot.direction = 2;
		else if (pre.robot.direction == 4)
			pre.robot.direction = 3;
		else if (pre.robot.direction == 1)
			pre.robot.direction = 4;
	}
	else if (op == 3) {//ǰ���߶�һ��ʱǰ��
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
	else if (op == 4) {//��Ծ
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
	else if (op == 5) {//�����������������
		if (pre.cells[pre.robot.pos.x][pre.robot.pos.y].light == 1)
			pre.cells[pre.robot.pos.x][pre.robot.pos.y].light = 2;
		pre.num_lights++;//����������
	}
	return pre;
}

Map stepmap[30];//�洢ÿһ���ĵ�ͼ״̬
int lightnumber;
int excute(Map map0, int a, int b, int c, int d, int* arr1, int* arr2, int* arr3, int*arr4) {
	//����ִ�к���
	//�ֱ����ʼ��ͼ״̬��������������P1��P2�Ĳ�������a,b,c) ����Ӧ�Ĳ�������(����1,2,3)
	//ֻ�����������е����ӳ���
	stepmap[0] = map0; //��0λ�Ǵ���ʱ�ĳ�ʼ״̬

	lightnumber = 0;
	//�Ƶ�����
	for (int i = 0; i < map0.row; i++) {
		for (int j = 0; j < map0.col; j++) {
			if (map0.cells[i][j].light == 1) {
				lightnumber++;
			}
		}
	}

	int p = 1;  //�����ͼ״̬Ӧ��1��p-1λ
	for (int i = 0; i < a; i++) {
		if (stepmap[p - 1].num_lights == lightnumber) {
			break;
		}
		if (arr1[i] >= 1 && arr1[i] <= 5) {
			stepmap[p] = step(stepmap[p - 1], arr1[i]);
			p++;
		}
		else if (arr1[i] == 6) {//����P1
			for (int j = 0; j < b; j++) {
				stepmap[p] = step(stepmap[p - 1], arr2[j]);
				p++;
			}
		}
		else if (arr1[i] == 7) {//����P2
			for (int k = 0; k < c; k++) {
				stepmap[p] = step(stepmap[p - 1], arr3[k]);
				p++;
			}
		}
		else if (arr1[i] == 8) {//����P3
			for (int k = 0; k < d; k++) {
				stepmap[p] = step(stepmap[p - 1], arr4[k]);
				p++;
			}
		}

	}
	return p - 1;

}
