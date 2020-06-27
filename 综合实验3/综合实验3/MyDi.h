#pragma once


// MyDi 对话框

class MyDi : public CDialogEx
{
	DECLARE_DYNAMIC(MyDi)

public:
	MyDi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long lon;
	virtual BOOL OnInitDialog();
};
