// MyDia.cpp : 实现文件
//

#include "stdafx.h"
#include "8实验1.h"
#include "MyDia.h"
#include "afxdialogex.h"


// MyDia 对话框

IMPLEMENT_DYNAMIC(MyDia, CDialogEx)

MyDia::MyDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

MyDia::~MyDia()
{
}

void MyDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Text(pDX, IDC_EDIT2, c);
	DDX_Control(pDX, IDC_COMBO1, Box);
}


BEGIN_MESSAGE_MAP(MyDia, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDia::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDia 消息处理程序


void MyDia::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	int n = Box.GetCurSel();
	Box.GetLBText(n, s);
	//int c;
	if (s == _T("+")) {
		c = a + b;
	}
	if (s == _T("-")) {
		c = a - b;
	}
	if (s == _T("*")) {
		c = a*b;
	}
	if (s == _T("/")) {
		c = a / b;
	}
	if (s == _T("开平方")) {
		c = sqrt(a);
	}
	if (s == _T("倒数")) {
		c = 1 / a;
	}
	UpdateData(false);
}


BOOL MyDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	s = "";
	Box.AddString(_T("倒数"));
	Box.AddString(_T("开平方"));
	Box.AddString(_T("/"));
	Box.AddString(_T("*"));
	Box.AddString(_T("-"));
	Box.AddString(_T("+"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
