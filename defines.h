//ͨ�����ݽṹ
struct Position {
	int x, y; // x ��ʾ�кţ�y ��ʾ�к� 
};

struct Robot {
	Position pos; // ������λ�� 
	int direction; // �����˳���1ǰ��2��3�£�4��
};

struct Cell {
	int height; // �߶� 
	bool robot; // true/false�ֱ��ʾ��������/���ڸõ�Ԫ����
	int light;//��״̬��0����û�еƣ�1�����е�û������2�����е��ҵ���
};

struct Map {
	// ��Ԫ����ɶ�ά���飬MAX_ROW��MAX_COLΪ������ 
	Cell cells[6][8];
	int row, col;
	// ��Ч��������Ч����
	int num_lights;
	// ��ͼ��ͬʱֻ��һ��������
	Robot robot;
	// ÿ�����̵�ָ��������
};
