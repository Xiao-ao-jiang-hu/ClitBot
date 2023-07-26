#pragma once
#include <windows.h>
#include <stdio.h>


/***********************************************************************
在命令行中展示一张图片
参数： filename（char*），要展示的图片的路径
***********************************************************************/
int show(char* filename)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, filename, "rb"); // 只能显示bmp格式图片
	if (!file)
	{
		printf("图片文件打开失败！\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);

	LPBITMAPINFOHEADER bi = (LPBITMAPINFOHEADER)malloc(size);
	if (!bi)
	{
		printf("内存分配失败！\n");
		return -2;
	}

	fseek(file, sizeof(BITMAPFILEHEADER), SEEK_SET);
	fread(bi, 1, size, file);

	char Title[255] = { 0 };
	GetConsoleTitleA(Title, 255);
	HDC dc = GetDC(FindWindowA(0, Title));
	SetConsoleTitleA("第i步");


	SetDIBitsToDevice(dc, 50, 10, bi->biWidth, bi->biHeight, 0, -0, 0, bi->biHeight, bi + 1, (LPBITMAPINFO)bi, 0);
	Sleep(1000);
	return 0;
}



