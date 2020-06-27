#pragma once
#include "afxwin.h"


// MyDia 对话框

class MyDia : public CDialogEx
{
	DECLARE_DYNAMIC(MyDia)

public:
	MyDia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDia();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	int c;
	CComboBox Box;
	CString s;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
