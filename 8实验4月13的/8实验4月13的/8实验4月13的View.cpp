
// 8实验4月13的View.cpp : CMy8实验4月13的View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8实验4月13的.h"
#endif

#include "8实验4月13的Doc.h"
#include "8实验4月13的View.h"
#include "MyDia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8实验4月13的View

IMPLEMENT_DYNCREATE(CMy8实验4月13的View, CView)

BEGIN_MESSAGE_MAP(CMy8实验4月13的View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Menu, &CMy8实验4月13的View::OnMenu)
END_MESSAGE_MAP()

// CMy8实验4月13的View 构造/析构

CMy8实验4月13的View::CMy8实验4月13的View()
{
	// TODO: 在此处添加构造代码

}

CMy8实验4月13的View::~CMy8实验4月13的View()
{
}

BOOL CMy8实验4月13的View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy8实验4月13的View 绘制

void CMy8实验4月13的View::OnDraw(CDC* /*pDC*/)
{
	CMy8实验4月13的Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy8实验4月13的View 诊断

#ifdef _DEBUG
void CMy8实验4月13的View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8实验4月13的View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8实验4月13的Doc* CMy8实验4月13的View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8实验4月13的Doc)));
	return (CMy8实验4月13的Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8实验4月13的View 消息处理程序

CString s;

void CMy8实验4月13的View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	if (t == IDOK) {
		s = cfd.GetPathName();
		dc.TextOutW(100, 100, s);
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy8实验4月13的View::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	MyDia *dlg = new MyDia;
	UpdateData(true);
	dlg->ss = s;
	dlg->set = true;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(1);
	UpdateData(false);
}
