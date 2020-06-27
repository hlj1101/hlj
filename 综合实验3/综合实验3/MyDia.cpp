// MyDia.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验3.h"
#include "MyDia.h"
#include "afxdialogex.h"


// MyDia 对话框

IMPLEMENT_DYNAMIC(MyDia, CDialogEx)

MyDia::MyDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, lo(0)
{

}

MyDia::~MyDia()
{
}

void MyDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, lo);
}


BEGIN_MESSAGE_MAP(MyDia, CDialogEx)
END_MESSAGE_MAP()


// MyDia 消息处理程序
