// MyDia.cpp : 实现文件
//

#include "stdafx.h"
#include "8实验4月13的.h"
#include "MyDia.h"
#include "afxdialogex.h"


// MyDia 对话框

IMPLEMENT_DYNAMIC(MyDia, CDialogEx)

MyDia::MyDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, ss(_T(""))
{

}

MyDia::~MyDia()
{
}

void MyDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ss);
	DDX_Control(pDX, IDC_LIST1, h);
}


BEGIN_MESSAGE_MAP(MyDia, CDialogEx)
END_MESSAGE_MAP()


// MyDia 消息处理程序


BOOL MyDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (set) {
		h.AddString(ss);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
