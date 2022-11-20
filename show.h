//#include<bits/stdc++.h>

#include<Windows.h>
#include<wingdi.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


/***********************************************************************
����������չʾһ��ͼƬ
������ filename��char*����Ҫչʾ��ͼƬ��·��
***********************************************************************/
void show(char* filename)
{
	//��ȡͼ���ļ�
	FILE* fp;
	errno_t err = fopen_s(&fp, filename, "rb");
	//FILE* fp = fopen_s(&tmp, "outputs/output.bmp", "rb");//������ļ�
	if (!fp) {
		cout << "�ļ�δ�򿪣�\n";
		exit(0);
	}
	long width, height;
	BITMAPFILEHEADER fileHead;//λͼ�ļ�ͷ
	fread(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);//��fp�ж�ȡBITMAPFILEHEADER��Ϣ��fileHead��,ͬʱfp��ָ���ƶ�
	BITMAPINFOHEADER infoHead;//λͼ��Ϣͷ
	fread(&infoHead, sizeof(BITMAPINFOHEADER), 1, fp);//��fp�ж�ȡBITMAPINFOHEADER��Ϣ��infoHead��,ͬʱfp��ָ���ƶ�
	width = infoHead.biWidth;
	height = infoHead.biHeight;


	char* bmpBuf = new char[width * height * 3];
	fseek(fp, long(sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)), 0);//��λ����ʼλ��
	fread(bmpBuf, sizeof(char), width * height * 3, fp);
	fclose(fp);

	//��ʾͼ��
	HWND hwnd = GetForegroundWindow();//���ھ��
	HDC hdc = GetDC(hwnd);//��ͼ���
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

