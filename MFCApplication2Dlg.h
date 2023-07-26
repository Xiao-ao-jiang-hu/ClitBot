
// MFCApplication2Dlg.h: 头文件
//

#pragma once


// CMFCApplication2Dlg 对话框
class CMFCApplication2Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// left
	CButton button1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CStatic img;
	afx_msg void OnStnClickedStaticImg();
	CStatic commands;
	afx_msg void OnStnClickedStaticCommands();

	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	CButton right_but;
	CButton forward_but;
	CButton jump_but;
	CButton light_but;
	CButton delete_but;
	CButton run_but;
	CButton reset_but;
	CStatic info_text;
	afx_msg void OnBnClickedButton10();
	CButton x;
	afx_msg void OnBnClickedButton11();
	CStatic P1;
	CStatic P2;
	afx_msg void OnStnClickedStaticP2();
	afx_msg void OnStnClickedStaticP1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	CButton P1_but;
	CButton P2_but;
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton12();
	afx_msg void On15();
	afx_msg void On21();
	CButton load_button;

	void disable();
	void enable();
	CStatic limit_text;
	afx_msg void OnBnClickedButton17();
	CStatic P3;
	afx_msg void OnBnClickedButton18();
	CButton P3_but;
	afx_msg void OnStnClickedStaticInfo();
};
