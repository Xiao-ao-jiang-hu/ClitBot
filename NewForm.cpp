// NewForm.cpp: 实现文件
//
#include "pch.h"
#include "afxdialogex.h"
#include "NewForm.h"
#include"resource.h"
// NewForm 对话框

IMPLEMENT_DYNAMIC(NewForm, CDialogEx)

NewForm::NewForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_D2, pParent)
{

}

NewForm::~NewForm()
{
}

void NewForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewForm, CDialogEx)
END_MESSAGE_MAP()


// NewForm 消息处理程序
