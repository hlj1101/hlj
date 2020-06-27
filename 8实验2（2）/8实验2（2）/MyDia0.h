#pragma once


// MyDia0 对话框

class MyDia0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDia0)

public:
	MyDia0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDia0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	int x;
	int y;
	int a;
	int b;
};
