#pragma once
#include<fstream>
#include<iostream>
#include<Windows.h>
#include<cstring>
#include"defines.h"
using namespace std;




//背景画布所需变量
unsigned char* pBackgroundBuf;//读入图像数据的指针
int backgroundWidth;//图像的宽
int backgroundHeight;//图像的高
RGBQUAD* pColorTableBackground;//颜色表指针
int biBitCountBackground;//图像类型
int lineBytebackground;//背景每行字节数



/***********************************************************************
读入背景画布
***********************************************************************/
bool readBackground(char* backgroundName)
{
	//二进制读方式打开指定的图像文件
	FILE* fp;
	errno_t err = fopen_s(&fp, backgroundName, "rb");

	//跳过位图文件头结构BITMAPFILEHEADER
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);
	//定义位图信息头结构变量，读取位图信息头进内存，存放在变量head中
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	//获取图像宽、高、每像素所占位数等信息
	backgroundWidth = head.biWidth;
	backgroundHeight = head.biHeight;
	biBitCountBackground = head.biBitCount;
	//定义变量，计算图像每行像素所占的字节数（必须是4的倍数）
	lineBytebackground = (backgroundWidth * biBitCountBackground / 8 + 3) / 4 * 4;
	//申请位图数据所需要的空间，读位图数据进内存
	pBackgroundBuf = new unsigned char[lineBytebackground * backgroundHeight];
	fread(pBackgroundBuf, 1, lineBytebackground * backgroundHeight, fp);
	//关闭文件
	fclose(fp);
	return 1;
}




//要添加的部分需要的变量
unsigned char* pAddBuf;//读入图像数据的指针
int AddWidth;//图像的宽
int AddHeight;//图像的高
RGBQUAD* pColorTableAdd;//颜色表指针
int biBitCountAdd;//图像类型
int lineByteadd;//每行字节数





/***********************************************************************
读入要添加的素材
参数：AddName（char*)，素材的路径
***********************************************************************/
bool readAdd(char* AddName)
{
	FILE* fp;
	errno_t err = fopen_s(&fp, AddName, "rb");

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
* 函数名称：
* saveBmp()
*
*函数参数：
*  char *bmpName -文件名字及路径
*  unsigned char *imgBuf  -待存盘的位图数据
*  int width   -像素为单位待存盘位图的宽
*  int  height  -像素为单位待存盘位图高
*  int biBitCount   -每像素所占位数
*  RGBQUAD *pColorTable  -颜色表指针
***********************************************************************/
bool saveBmp(char* bmpName, unsigned char* imgBuf, int width, int height,
	int biBitCount, RGBQUAD* pColorTable)
{
	//如果位图数据指针为0,则没有数据传入,函数返回
	if (!imgBuf)
		return 0;
	//颜色表大小,以字节为单位,灰度图像颜色表为1024字节,彩色图像颜色表大小为0
	int colorTablesize = 0;
	//待存储图像数据每行字节数为4的倍数
	int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;
	//以二进制写的方式打开文件
	FILE* fp;
	errno_t err = fopen_s(&fp, bmpName, "wb");
	//FILE* fp = fopen(bmpName, "wb");
	if (fp == 0) return 0;
	//申请位图文件头结构变量，填写文件头信息
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;//bmp类型
	//bfSize是图像文件4个组成部分之和
	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
		+ colorTablesize + lineByte * height;
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	//bfOffBits是图像文件前三个部分所需空间之和
	fileHead.bfOffBits = 54 + colorTablesize;
	//写文件头进文件
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);
	//申请位图信息头结构变量，填写信息头信息
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
	//写位图信息头进内存
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	//写位图数据进文件
	fwrite(imgBuf, height * lineByte, 1, fp);
	//关闭文件
	fclose(fp);
	return 1;
}



/***********************************************************************
函数名：combine
参数：x(int), y(int)，指示图像左上角到画布左上角的x、y轴偏移量
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
函数名：draw_step
绘制一个状态
参数：n(int), rock_indexies(int*), WritePath(char*)
第一个代表共有n个石块
第二个代表每一个石块的偏移量，按顺序存储
第三个代表存储图片的路径和名称
第四个代表light的状态，0为没有灯，1为有灯但未点亮，
***********************************************************************/
void draw_step(char* WritePath, Map map)
{   //int n, int *rock_indexies,
	//读入背景
	char bg[] = "resources/background.bmp";
	char rock[] = "resources/single_rock.bmp";
	char light[] = "resources/lighted.bmp";
	char unlight[] ="resources/unlighted.bmp";
	char back[] = "resources/back.bmp";
	char forward[] = "resources/forward.bmp";
	char right[] = "resources/right.bmp";
	char left[] = "resources/left.bmp";
	int h, x, y;
	int x0 = 400, y0 = 300;
	readBackground(bg);

	//临时定义一个map，要调用请删除这几行

	
	//绘制部分
	//遍历每一个单元格
	for (int i = 0; i < map.row; i++) {
		for (int j = 0; j < map.col; j++) {
			//画石头
			for (int k = 0; k < map.cells[i][j].height; k++) {
				readAdd(rock);
				h = map.cells[i][j].height;
				x = x0 + 85 * i - 80 * j;
				y = y0 + 25 * i + 20 * j - 70 * k;
				combine(x, y);
				delete[] pAddBuf;
			}
			//有灯画灯
			if (map.cells[i][j].light == 2) {
				readAdd(light);
				h = map.cells[i][j].height;
				x = x0 + 85 * i - 80 * j + 90;
				y = y0 + 25 * i + 20 * j - 70 * h + 50;
				combine(x, y);
				delete[] pAddBuf;
			}else if (map.cells[i][j].light == 1) {
				readAdd(unlight);
				h = map.cells[i][j].height;
				x = x0 + 85 * i - 80 * j + 90;
				y = y0 + 25 * i + 20 * j - 70 * h + 50;
				combine(x, y);
				delete[] pAddBuf;
			}
			//有机器人画机器人
			if (map.cells[i][j].robot) {
				if (map.robot.direction == 1) {
						readAdd(forward);
				}else if (map.robot.direction == 2) {
					readAdd(left);
				}else if (map.robot.direction == 3) {
					readAdd(back);
				}else if (map.robot.direction == 4) {
					readAdd(right);
				}
				h = map.cells[i][j].height;
				x = x0 + 85 * i - 80 * j + 70;
				y = y0 + 25 * i + 20 * j - 70 * h - 16;
				combine(x, y);
				delete[] pAddBuf;
			}
		}
	}
	
	//存盘
	saveBmp(WritePath, pBackgroundBuf, backgroundWidth, backgroundHeight, biBitCountBackground, pColorTableBackground);

	// 清除背景画布变量
	delete[] pBackgroundBuf;

}

