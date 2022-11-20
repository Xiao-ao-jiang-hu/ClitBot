//ͨ�����ݽṹ
#pragma once

struct Position {
	int x, y; // x ��ʾ�кţ�y ��ʾ�к� 
};

struct Robot {
	Position pos; // ������λ�� 
	int direction; // �����˳���1ǰ��2��3�£�4��
};

struct Cell {
	int height; // �߶� 
	int light;//��״̬��0����û�еƣ�1�����е�û������2�����е��ҵ���
	bool robot;//��Ԫ�����Ƿ��л�����
};

struct Map {
	// ��Ԫ����ɶ�ά���飬MAX_ROW��MAX_COLΪ������ 
	Cell cells[6][8];
	// ��Ч��������Ч����
	int row, col;
	//�Ѿ������ĵƵ���Ŀ
	int num_lights;
	Robot robot;
};
