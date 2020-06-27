// MyDi.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验3.h"
#include "MyDi.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "综合实验3Doc.h"
#include "综合实验3View.h"




// MyDi 对话框

IMPLEMENT_DYNAMIC(MyDi, CDialogEx)

MyDi::MyDi(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, lon(0)
{

}

MyDi::~MyDi()
{
}

void MyDi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, lon);
}


BEGIN_MESSAGE_MAP(MyDi, CDialogEx)
END_MESSAGE_MAP()


// MyDi 消息处理程序


BOOL MyDi::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	C综合实验3View* pView = (C综合实验3View*)pFrame->GetActiveView();
	lon = pView->ch;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
