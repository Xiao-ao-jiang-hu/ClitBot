#pragma once
#include "afxdialogex.h"

// NewForm 对话框

class NewForm : public CDialogEx
{
	DECLARE_DYNAMIC(NewForm)

public:
	NewForm(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewForm();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
