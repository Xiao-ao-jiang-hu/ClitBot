//#include<bits/stdc++.h>

#include<Windows.h>
#include<wingdi.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


/***********************************************************************
在命令行中展示一张图片
参数： filename（char*），要展示的图片的路径
***********************************************************************/
void show(char* filename)
{
	//读取图像文件
	FILE* fp;
	errno_t err = fopen_s(&fp, filename, "rb");
	//FILE* fp = fopen_s(&tmp, "outputs/output.bmp", "rb");//读入的文件
	if (!fp) {
		cout << "文件未打开！\n";
		exit(0);
	}
	long width, height;
	BITMAPFILEHEADER fileHead;//位图文件头
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);//从fp中读取BITMAPFILEHEADER信息到fileHead中,同时fp的指针移动
	BITMAPINFOHEADER infoHead;//位图信息头
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);//从fp中读取BITMAPINFOHEADER信息到infoHead中,同时fp的指针移动
	width = infoHead.biWidth;
	height = infoHead.biHeight;


	char* bmpBuf = new char[width * height * 3];
	fseek(fp, long(sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), 0);//定位到起始位置
	fread(bmpBuf, sizeof(char), width * height * 3, fp);
	fclose(fp);

	//显示图像
	HWND hwnd = GetForegroundWindow();//窗口句柄
	HDC hdc = GetDC(hwnd);//绘图句柄
	BYTE b, g, r;
	char* tmp = bmpBuf;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			b = *tmp++;
			g = *tmp++;
			r = *tmp++;
			SetPixel(hdc, i, 150 + height - j, RGB(r, g, b));
		}
	}

}

