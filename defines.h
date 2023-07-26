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
	int height=0; // �߶� 
	int light=0;//��״̬��0����û�еƣ�1�����е�û������2�����е��ҵ���
	bool robot=0;//��Ԫ�����Ƿ��л�����
};

// ������
struct Light {
	Position pos; // ��λ��
	bool lighten; // �Ƿ񱻵���
};

struct Map {
	// ��Ԫ����ɶ�ά���飬MAX_ROW��MAX_COLΪ������ 
	Cell cells[6][8];
	// ��Ч��������Ч����
	int row, col;
	// �Ƽ�¼��MAX_LITΪ������
	Light lights[50];
	//�Ѿ������ĵƵ���Ŀ
	int num_lights = 0;
	Robot robot;
	// ÿ�����̵�ָ��������
	int op_limit[4] = { 0,0,0,0 };
};
