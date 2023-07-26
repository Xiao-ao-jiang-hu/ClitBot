#pragma once
#include <windows.h>
#include <stdio.h>


/***********************************************************************
����������չʾһ��ͼƬ
������ filename��char*����Ҫչʾ��ͼƬ��·��
***********************************************************************/
int show(char* filename)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, filename, "rb"); // ֻ����ʾbmp��ʽͼƬ
	if (!file)
	{
		printf("ͼƬ�ļ���ʧ�ܣ�\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);

	LPBITMAPINFOHEADER bi = (LPBITMAPINFOHEADER)malloc(size);
	if (!bi)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		return -2;
	}

	fseek(file, sizeof(BITMAPFILEHEADER), SEEK_SET);
	fread(bi, 1, size, file);

	char Title[255] = { 0 };
	GetConsoleTitleA(Title, 255);
	HDC dc = GetDC(FindWindowA(0, Title));
	SetConsoleTitleA("��i��");


	SetDIBitsToDevice(dc, 50, 10, bi->biWidth, bi->biHeight, 0, -0, 0, bi->biHeight, bi + 1, (LPBITMAPINFO)bi, 0);
	Sleep(1000);
	return 0;
}



