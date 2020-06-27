
// MFC4实验1View.cpp: CMFC4实验1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4实验1.h"
#endif

#include "MFC4实验1Doc.h"
#include "MFC4实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4实验1View

IMPLEMENT_DYNCREATE(CMFC4实验1View, CView)

BEGIN_MESSAGE_MAP(CMFC4实验1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC4实验1View 构造/析构

CMFC4实验1View::CMFC4实验1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4实验1View::~CMFC4实验1View()
{
}

BOOL CMFC4实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4实验1View 绘图

void CMFC4实验1View::OnDraw(CDC* pDC)
{
	CMFC4实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4实验1View 诊断

#ifdef _DEBUG
void CMFC4实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4实验1Doc* CMFC4实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4实验1Doc)));
	return (CMFC4实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4实验1View 消息处理程序


void CMFC4实验1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4实验1Doc* pDoc = GetDocument();
	pDoc->a = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4实验1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4实验1Doc* pDoc = GetDocument();
	pDoc->b = point.x;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC4实验1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFC4实验1Doc* pDoc = GetDocument();
	int i = abs(pDoc->b - pDoc->a);
	if (nFlags)
		pDoc->count = pDoc->count++;
	CString s;
	s.Format(_T("MouseMove发生了 %d 次,横向移动%d个像素发生一次"), pDoc->count, i);
	dc.TextOutW(200, 200, s);
	CView::OnMouseMove(nFlags, point);
}
