
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "draw_all.h"
#include "afxdialogex.h"
#include "load.h"
#include <ctime>
#include "excute.h"
#include "run.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<string>
#include <fstream>

//定义一些变量和函数
int window = 0;
Map init_map;
CString s2c(std::string& str)
{
	CString cstr(str.c_str(), str.length());
	return  cstr;
}
void map_load1(char* path);
bool map_load(char* path);
std::string text0 = "";
std::string text1 = "";
std::string text2 = "";
std::string text3 = "";
CString ops0 = s2c(text0);
CString ops1 = s2c(text1);
CString ops2 = s2c(text2);
CString ops3 = s2c(text3);

int commands0[20];
int commands1[20];
int commands2[20];
int commands3[20];
int i, j, k, l = 0;
Map map0;




// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void tishi();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(15, &CAboutDlg::tishi)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, button1);
	DDX_Control(pDX, IDC_STATIC_IMG, img);
	DDX_Control(pDX, IDC_STATIC_COMMANDS, commands);
	DDX_Control(pDX, IDC_BUTTON2, right_but);
	DDX_Control(pDX, IDC_BUTTON6, forward_but);
	DDX_Control(pDX, IDC_BUTTON3, jump_but);
	DDX_Control(pDX, IDC_BUTTON4, light_but);
	DDX_Control(pDX, IDC_BUTTON7, delete_but);
	DDX_Control(pDX, IDC_BUTTON8, run_but);
	DDX_Control(pDX, IDC_BUTTON9, reset_but);
	DDX_Control(pDX, IDC_STATIC_INFO, info_text);
	DDX_Control(pDX, IDC_BUTTON11, x);
	DDX_Control(pDX, IDC_STATIC_P1, P1);
	DDX_Control(pDX, IDC_STATIC_P2, P2);
	DDX_Control(pDX, IDC_BUTTON15, P1_but);
	DDX_Control(pDX, IDC_BUTTON16, P2_but);
	DDX_Control(pDX, IDC_BUTTON12, load_button);
	DDX_Control(pDX, IDC_STATIC_LIMITS, limit_text);
	DDX_Control(pDX, IDC_STATIC_P3, P3);
	DDX_Control(pDX, IDC_BUTTON18, P3_but);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_STATIC_IMG, &CMFCApplication2Dlg::OnStnClickedStaticImg)
	ON_STN_CLICKED(IDC_STATIC_COMMANDS, &CMFCApplication2Dlg::OnStnClickedStaticCommands)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication2Dlg::OnBnClickedButton11)
	ON_STN_CLICKED(IDC_STATIC_P2, &CMFCApplication2Dlg::OnStnClickedStaticP2)
	ON_STN_CLICKED(IDC_STATIC_P1, &CMFCApplication2Dlg::OnStnClickedStaticP1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication2Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication2Dlg::OnBnClickedButton14)
	ON_STN_CLICKED(IDC_STATIC_INFO, &CMFCApplication2Dlg::OnStnClickedStaticInfo)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication2Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication2Dlg::OnBnClickedButton16)
	ON_COMMAND(21, &CMFCApplication2Dlg::On21)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication2Dlg::OnBnClickedButton17)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序


BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	//初始化原始地图
	HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, s2c((string)"resources/background.bmp"), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	img.SetBitmap(hbmp);

	// 加载地图前全部不可用
	button1.EnableWindow(0);
	right_but.EnableWindow(0);
	forward_but.EnableWindow(0);
	jump_but.EnableWindow(0);
	light_but.EnableWindow(0);
	reset_but.EnableWindow(0);
	run_but.EnableWindow(0);
	delete_but.EnableWindow(0);
	P1_but.EnableWindow(0);
	P2_but.EnableWindow(0);
	P3_but.EnableWindow(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//展示背景




void CMFCApplication2Dlg::OnBnClickedButton1()
{
	
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " Left";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 1;
		i++;
	}
	else if (window == 1 && j < map0.op_limit[1]) {
		text1 = text1 + " Left";
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
		commands1[j] = 1;
		j++;
	}else if (window == 2 && k < map0.op_limit[2]) {
		text2 = text2 + " Left";
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
		commands2[k] = 1;
		k++;
	}
	else if (window == 3 && l < map0.op_limit[3]) {
		text3 = text3 + " Left";
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
		commands3[l] = 1;
		l++;
	}

}


void CMFCApplication2Dlg::OnStnClickedStaticImg()
{
	// TODO: 在此添加控件通知处理程序代码

}


//在此处调用和调试
void CMFCApplication2Dlg::OnStnClickedStaticCommands()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 0;
	
}





void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " Right";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 2;
		i++;
	}
	else if (window == 1 && j < map0.op_limit[1]) {
		text1 = text1 + " Right";
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
		commands1[j] = 2;
		j++;
	}
	else if (window == 2 && k < map0.op_limit[2]) {
		text2 = text2 + " Right";
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
		commands2[k] = 2;
		k++;
	}
	else if (window == 3 && l < map0.op_limit[3]) {
		text3 = text3 + " Right";
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
		commands3[l] = 2;
		l++;
	}
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " Forward";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 3;
		i++;
	}
	else if (window == 1 && j < map0.op_limit[1]) {
		text1 = text1 + " Forward";
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
		commands1[j] = 3;
		j++;
	}
	else if (window == 2 && k < map0.op_limit[2]) {
		text2 = text2 + " Forward";
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
		commands2[k] = 3;
		k++;
	}
	else if (window == 3 && l < map0.op_limit[3]) {
		text3 = text3 + " Forward";
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
		commands3[l] = 3;
		l++;
	}
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " Jump";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 4;
		i++;
	}
	else if (window == 1 && j < map0.op_limit[1]) {
		text1 = text1 + " Jump";
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
		commands1[j] = 4;
		j++;
	}
	else if (window == 2 && k < map0.op_limit[2]) {
		text2 = text2 + " Jump";
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
		commands2[k] = 4;
		k++;
	}
	else if (window == 3 && l < map0.op_limit[3]) {
		text3 = text3 + " Jump";
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
		commands3[l] = 4;
		l++;
	}
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " Light";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 5;
		i++;
	}
	else if (window == 1 && j < map0.op_limit[1]) {
		text1 = text1 + " Light";
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
		commands1[j] = 5;
		j++;
	}
	else if (window == 2 && k < map0.op_limit[2]) {
		text2 = text2 + " Light";
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
		commands2[k] = 5;
		k++;
	}
	else if (window == 3 && l < map0.op_limit[3]) {
		text3 = text3 + " Light";
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
		commands3[l] = 5;
		l++;
	}
}

//delete
void CMFCApplication2Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0) {
		int len = text0.size();
		if (len) {
			int m = text0.find_last_of(" ");
			text0.erase(m, len - m);
		}
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i - 1] = 0;
		i--;
	}
	else if (window == 1) {
		int len = text1.size();
		if (len) {
			int m = text1.find_last_of(" ");
			text1.erase(m, len - m);
			commands1[j - 1] = 0;
			j--;
		}
		ops1 = s2c(text1);
		P1.SetWindowTextW(ops1);
	}
	else if (window == 2) {
		int len = text2.size();
		if (len) {
			int m = text2.find_last_of(" ");
			text2.erase(m, len - m);
			commands2[k - 1] = 0;
			k--;
		}
		ops2 = s2c(text2);
		P2.SetWindowTextW(ops2);
	}
	else if (window == 3) {
		int len = text3.size();
		if (len) {
			int m = text3.find_last_of(" ");
			text3.erase(m, len - m);
			commands3[l - 1] = 0;
			l--;
		}
		ops3 = s2c(text3);
		P3.SetWindowTextW(ops3);
	}

}

void CMFCApplication2Dlg::enable() {
	// 恢复按钮可用性
	button1.EnableWindow(TRUE);
	right_but.EnableWindow(TRUE);
	forward_but.EnableWindow(TRUE);
	jump_but.EnableWindow(TRUE);
	light_but.EnableWindow(TRUE);
	reset_but.EnableWindow(TRUE);
	run_but.EnableWindow(TRUE);
	delete_but.EnableWindow(TRUE);
	P1_but.EnableWindow(1);
	P2_but.EnableWindow(1);
	load_button.EnableWindow(1);
	P3_but.EnableWindow(1);
}

void CMFCApplication2Dlg::disable() {
	button1.EnableWindow(0);
	right_but.EnableWindow(0);
	forward_but.EnableWindow(0);
	jump_but.EnableWindow(0);
	light_but.EnableWindow(0);
	reset_but.EnableWindow(0);
	run_but.EnableWindow(0);
	delete_but.EnableWindow(0);
	P1_but.EnableWindow(0);
	P2_but.EnableWindow(0);
	load_button.EnableWindow(0);
	P3_but.EnableWindow(0);
}

void CMFCApplication2Dlg::OnBnClickedButton8()
{
	// 禁用按钮
	string fir = "outputs/step";
	string sec = "1";
	string thi = ".bmp";
	string path = fir + sec + thi;
	for (int i = 1; i <= 999; i++) {
		sec = to_string(i);
		path = fir + sec + thi;
		char* str = (char*)path.c_str();
		remove(str);
	}
	CMFCApplication2Dlg::disable();
	// 显示running
	text0 = text0 + " \n \n Running......";
	ops0 = s2c(text0);
	commands.SetWindowTextW(ops0);

	// 画图，展示图片
	int show_num = run_draw(map0,commands0, commands1, commands2, commands3, i, j, k, l);
	for (int i = 1; i <= show_num; i++) {
		string step_str = (string)"outputs" + (string)"/" + (string)"step" + to_string(i) + (string)".bmp";
		HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, s2c(step_str), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		img.SetBitmap(hbmp);
		Sleep(1000);
	}
	
	int len = text0.size();
	if (len) {
		int m = text0.find_last_of(" ");
		text0.erase(len - 18,18);
	}
	ops0 = s2c(text0);
	commands.SetWindowTextW(ops0);
	if(stepmap[show_num].num_lights==lightnumber) {
		//弹出通关对话框
		AfxMessageBox(_T("通关力！！"));
	}
	else {
		AfxMessageBox(_T("坏了，没过"));
	}
	CMFCApplication2Dlg::enable();
}



void CMFCApplication2Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	text0 = "";
	ops0 = s2c(text0);
	commands.SetWindowTextW(ops0);
	text1 = "";
	ops1 = s2c(text1);
	P1.SetWindowTextW(ops1);
	text2 = "";
	ops2 = s2c(text2);
	P2.SetWindowTextW(ops2);
	text3 = "";
	ops3 = s2c(text3);
	P3.SetWindowTextW(ops3);
	window = 0;
	for (int ii = 0; ii < i; ii++)//c or cpp language
	{
		commands0[ii] = 0;
	}
	for (int ii = 0; ii < j; ii++)//c or cpp language
	{
		commands1[l] = 0;
	}
	for (int ii = 0; ii < k; ii++)//c or cpp language
	{
		commands2[ii] = 0;
	}
	for (int ii = 0; ii < l; ii++)//c or cpp language
	{
		commands3[ii] = 0;
	}
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	char aa[] = "outputs/step0.bmp";
	draw_step(aa, map0);
	HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, s2c((string)aa), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	img.SetBitmap(hbmp);


}


void CMFCApplication2Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	info_text.ShowWindow(1);
	x.ShowWindow(1);

}


void CMFCApplication2Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	info_text.ShowWindow(0);
	x.ShowWindow(0);
}


void CMFCApplication2Dlg::OnStnClickedStaticP2()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 2;
}


void CMFCApplication2Dlg::OnStnClickedStaticP1()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 1;
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	window = 0;
}


void CMFCApplication2Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 1;
}


void CMFCApplication2Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 2;
}


void CMFCApplication2Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " P1";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 6;
		i++;
	}
}


void CMFCApplication2Dlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " P2";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 7;
		i++;
	}
}





void CAboutDlg::tishi()
{
	// TODO: 在此添加命令处理程序代码
	

}


void CMFCApplication2Dlg::On21()
{

}


void CMFCApplication2Dlg::OnBnClickedButton12()
{
	// 读文件（未完成）
	map0 = Load("map.map");
	
	map0.row = 5;
	map0.col = 5;
	/*
	map0.cells[0][0].height = 4;
	map0.cells[0][0].light = 1;
	map0.cells[0][1].height = 3;

	map0.cells[1][0].height = 3;
	map0.cells[1][1].height = 2;
	map0.cells[2][1].height = 1;
	map0.cells[1][1].light = 1;
	map0.cells[2][0].height = 1;
	map0.cells[2][1].height = 2;
	map0.cells[2][2].height = 1;
	map0.cells[1][2].height = 1;
	map0.cells[0][2].height = 1;
	map0.cells[0][3].height = 1;
	map0.cells[0][4].height = 1;
	map0.cells[0][5].height = 1;
	map0.cells[3][0].height = 1;
	map0.cells[4][0].height = 1;
	map0.cells[4][4].height = 1;
	map0.robot.pos.x = 4;
	map0.robot.pos.y = 0;
	map0.cells[4][0].robot = 1;
	map0.robot.direction = 2;
	*/
	// 画初始地图状态并显示
	char aa[] = "outputs/step0.bmp";
	draw_step(aa, map0);
	HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, s2c((string)aa), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	img.SetBitmap(hbmp);

	string limits_show;
	limits_show = "过程指令数上限： Main：" + to_string(map0.op_limit[0]) +"    P1："+ to_string(map0.op_limit[1])+"    P2："+to_string(map0.op_limit[2]) + "    P3：" + to_string(map0.op_limit[3]);
	CString lms = s2c(limits_show);
	limit_text.SetWindowTextW(lms);
	// 完成后设为可用
	button1.EnableWindow(1);
	right_but.EnableWindow(1);
	forward_but.EnableWindow(1);
	jump_but.EnableWindow(1);
	light_but.EnableWindow(1);
	reset_but.EnableWindow(1);
	run_but.EnableWindow(1);
	delete_but.EnableWindow(1);
	P1_but.EnableWindow(1);
	P2_but.EnableWindow(1);
	P3_but.EnableWindow(1);

}



void CMFCApplication2Dlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	window = 3;
}


void CMFCApplication2Dlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	if (window == 0 && i < map0.op_limit[0]) {
		text0 = text0 + " P3";
		ops0 = s2c(text0);
		commands.SetWindowTextW(ops0);
		commands0[i] = 8;
		i++;
	}
}


void CMFCApplication2Dlg::OnStnClickedStaticInfo()
{
	// TODO: 在此添加控件通知处理程序代码
}

