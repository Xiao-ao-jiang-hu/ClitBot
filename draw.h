#include<fstream>
#include<iostream>
#include<Windows.h>
#include<cstring>
#include"defines.h"
using namespace std;




//���������������
unsigned char* pBackgroundBuf;//����ͼ�����ݵ�ָ��
int backgroundWidth;//ͼ��Ŀ�
int backgroundHeight;//ͼ��ĸ�
RGBQUAD* pColorTableBackground;//��ɫ��ָ��
int biBitCountBackground;//ͼ������
int lineBytebackground;//����ÿ���ֽ���



/***********************************************************************
���뱳������
***********************************************************************/
bool readBackground(char* backgroundName)
{
	//�����ƶ���ʽ��ָ����ͼ���ļ�
	FILE* fp;
	errno_t err = fopen_s(&fp, backgroundName, "rb");
	//FILE* fp = fopen(backgroundName, "rb");
	if (fp == 0) {
		cout << "No such background file";
		return 0;
	}
	//����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);
	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	//��ȡͼ����ߡ�ÿ������ռλ������Ϣ
	backgroundWidth = head.biWidth;
	backgroundHeight = head.biHeight;
	biBitCountBackground = head.biBitCount;
	//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����
	lineBytebackground = (backgroundWidth * biBitCountBackground / 8 + 3) / 4 * 4;
	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�
	pBackgroundBuf = new unsigned char[lineBytebackground * backgroundHeight];
	fread(pBackgroundBuf, 1, lineBytebackground * backgroundHeight, fp);
	//�ر��ļ�
	fclose(fp);
	return 1;
}




//Ҫ��ӵĲ�����Ҫ�ı���
unsigned char* pAddBuf;//����ͼ�����ݵ�ָ��
int AddWidth;//ͼ��Ŀ�
int AddHeight;//ͼ��ĸ�
RGBQUAD* pColorTableAdd;//��ɫ��ָ��
int biBitCountAdd;//ͼ������
int lineByteadd;//ÿ���ֽ���





/***********************************************************************
����Ҫ��ӵ��ز�
������AddName��char*)���زĵ�·��
***********************************************************************/
bool readAdd(char* AddName)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, AddName, "rb");
	//FILE* fp = fopen(AddName, "rb");
	if (fp == 0) {
		cout << "no such add file";
		return 0;
	}
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);
	BITMAPINFOHEADER headadd;
	fread(&headadd, sizeof(BITMAPINFOHEADER), 1, fp);
	AddWidth = headadd.biWidth;
	AddHeight = headadd.biHeight;
	biBitCountAdd = headadd.biBitCount;
	lineByteadd = (AddWidth * biBitCountAdd / 8 + 3) / 4 * 4;
	pAddBuf = new unsigned char[lineByteadd * AddHeight + 4];
	fread(pAddBuf, 1, lineByteadd * AddHeight, fp);
	fclose(fp);
	return 1;
}





/***********************************************************************
* �������ƣ�
* saveBmp()
*
*����������
*  char *bmpName -�ļ����ּ�·��
*  unsigned char *imgBuf  -�����̵�λͼ����
*  int width   -����Ϊ��λ������λͼ�Ŀ�
*  int  height  -����Ϊ��λ������λͼ��
*  int biBitCount   -ÿ������ռλ��
*  RGBQUAD *pColorTable  -��ɫ��ָ��
***********************************************************************/
bool saveBmp(char* bmpName, unsigned char* imgBuf, int width, int height,
	int biBitCount, RGBQUAD* pColorTable)
{
	//���λͼ����ָ��Ϊ0,��û�����ݴ���,��������
	if (!imgBuf)
		return 0;
	//��ɫ���С,���ֽ�Ϊ��λ,�Ҷ�ͼ����ɫ��Ϊ1024�ֽ�,��ɫͼ����ɫ���СΪ0
	int colorTablesize = 0;
	//���洢ͼ������ÿ���ֽ���Ϊ4�ı���
	int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;
	//�Զ�����д�ķ�ʽ���ļ�
	FILE* fp;
	errno_t err = fopen_s(&fp, bmpName, "wb");
	//FILE* fp = fopen(bmpName, "wb");
	if (fp == 0) return 0;
	//����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;//bmp����
	//bfSize��ͼ���ļ�4����ɲ���֮��
	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
		+ colorTablesize + lineByte * height;
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	//bfOffBits��ͼ���ļ�ǰ������������ռ�֮��
	fileHead.bfOffBits = 54 + colorTablesize;
	//д�ļ�ͷ���ļ�
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);
	//����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
	BITMAPINFOHEADER head;
	head.biBitCount = biBitCount;
	head.biClrImportant = 0;
	head.biClrUsed = 0;
	head.biCompression = 0;
	head.biHeight = height;
	head.biPlanes = 1;
	head.biSize = 40;
	head.biSizeImage = lineByte * height;
	head.biWidth = width;
	head.biXPelsPerMeter = 0;
	head.biYPelsPerMeter = 0;
	//дλͼ��Ϣͷ���ڴ�
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	//дλͼ���ݽ��ļ�
	fwrite(imgBuf, height * lineByte, 1, fp);
	//�ر��ļ�
	fclose(fp);
	return 1;
}



/***********************************************************************
��������combine
������x(int), y(int)��ָʾͼ�����Ͻǵ��������Ͻǵ�x��y��ƫ����
***********************************************************************/

void combine(int x, int y) {

	for (int i = y + 1; i < AddHeight + y; i++) {
		for (int j = x * 3; j < lineByteadd + x * 3 - 2; j++) {
			if ((int)pAddBuf[lineByteadd * AddHeight - (i - y) * lineByteadd + j - x * 3] != 255) {
				pBackgroundBuf[lineBytebackground * backgroundHeight - i * lineBytebackground + j]
					= pAddBuf[lineByteadd * AddHeight - (i - y) * lineByteadd + j - x * 3];
			}
		}
	}
}



/***********************************************************************
��������draw_step
����һ��״̬
������n(int), rock_indexies(int*), WritePath(char*)
��һ��������n��ʯ��
�ڶ�������ÿһ��ʯ���ƫ��������˳��洢
����������洢ͼƬ��·��������
���ĸ�����light��״̬��0Ϊû�еƣ�1Ϊ�еƵ�δ������
***********************************************************************/
void draw_step(char* WritePath, Map map)
{   //int n, int *rock_indexies,
	//���뱳��
	char bg[] = "resources/background.bmp";
	char rock[] = "resources/single_rock.bmp";
	char light[] = "resources/lighted.bmp";
	char unlight[] ="resources/unlighted.bmp";
	char back[] = "resources/back.bmp";
	char forward[] = "resources/forward.bmp";
	char right[] = "resources/right.bmp";
	char left[] = "resources/left.bmp";
	readBackground(bg);

	//������ʯ��
	map.row = 5;
	map.col = 5;
	map.cells[0][0].height = 4;
	map.cells[0][1].height = 3;
	map.cells[1][0].height = 3;
	map.cells[1][1].height = 2;
	map.cells[2][0].height = 1;
	map.cells[2][1].height = 1;
	map.cells[2][2].height = 1;
	map.cells[1][2].height = 1;
	map.cells[0][2].height = 1;
	map.cells[0][3].height = 1;
	map.cells[0][4].height = 1;
	map.cells[0][5].height = 1;
	map.cells[3][0].height = 1;
	map.cells[4][0].height = 1;
	map.cells[4][4].height = 3;
	readAdd(rock);
	int x0 = 400, y0 = 300;
	for (int i = 0; i < map.row; i++) {
		for (int j = 0; j < map.col; j++) {
			for (int k = 0; k < map.cells[i][j].height; k++) {
				int h = map.cells[i][j].height;
				int x = x0 + 85 * i - 80 * j;
				int y = y0 + 25 * i + 20 * j - 70 * k;
				combine(x, y);
			}
		}
	}
	delete[] pAddBuf;
	/*
	if (if_light == 1) {
		readAdd(unlight);
		for (int i = 0; i < n; i++){
			int x = rock_indexies[2 * i];
			int y = rock_indexies[2 * i + 1];
			combine(x, y);
		}
	}
	else if (if_light == 2) {
		readAdd(light);
		for (int i = 0; i < n; i++) {
			int x = rock_indexies[2 * i];
			int y = rock_indexies[2 * i + 1];
			combine(x, y);
		}
	}
	delete[] pAddBuf;
	*/
	
	saveBmp(WritePath, pBackgroundBuf, backgroundWidth, backgroundHeight, biBitCountBackground, pColorTableBackground);

	// ���������������
	delete[] pBackgroundBuf;

}

