
// MFC4课堂1View.cpp: CMFC4课堂1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4课堂1.h"
#endif

#include "MFC4课堂1Doc.h"
#include "MFC4课堂1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4课堂1View

IMPLEMENT_DYNCREATE(CMFC4课堂1View, CView)

BEGIN_MESSAGE_MAP(CMFC4课堂1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC4课堂1View 构造/析构

CMFC4课堂1View::CMFC4课堂1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4课堂1View::~CMFC4课堂1View()
{
}

BOOL CMFC4课堂1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4课堂1View 绘图

void CMFC4课堂1View::OnDraw(CDC* pDC)
{
	CMFC4课堂1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4课堂1View 诊断

#ifdef _DEBUG
void CMFC4课堂1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4课堂1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4课堂1Doc* CMFC4课堂1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4课堂1Doc)));
	return (CMFC4课堂1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4课堂1View 消息处理程序


void CMFC4课堂1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4课堂1Doc* pDoc = GetDocument();
	SetCapture();
	pDoc->A = point.x;
	pDoc->B = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4课堂1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4课堂1Doc* pDoc = GetDocument();
	ReleaseCapture();
	pDoc->C = point.x;
	pDoc->D = point.y;
	CClientDC dc(this);
	CRect cr(pDoc->A, pDoc->B, pDoc->C, pDoc->D);
	dc.Rectangle(cr);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC4课堂1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("X:%d  Y:%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(0, 0, s);
	CView::OnMouseMove(nFlags, point);
}
