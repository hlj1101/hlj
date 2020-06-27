
// MFC1课外练习View.cpp: CMFC1课外练习View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC1课外练习.h"
#endif

#include "MFC1课外练习Doc.h"
#include "MFC1课外练习View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1课外练习View

IMPLEMENT_DYNCREATE(CMFC1课外练习View, CView)

BEGIN_MESSAGE_MAP(CMFC1课外练习View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC1课外练习View 构造/析构

CMFC1课外练习View::CMFC1课外练习View() noexcept
{
	// TODO: 在此处添加构造代码
	s2 = "春暖花开";
}

CMFC1课外练习View::~CMFC1课外练习View()
{
}

BOOL CMFC1课外练习View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC1课外练习View 绘图

void CMFC1课外练习View::OnDraw(CDC* pDC)
{
	CMFC1课外练习Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC1课外练习View 诊断

#ifdef _DEBUG
void CMFC1课外练习View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1课外练习View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1课外练习Doc* CMFC1课外练习View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1课外练习Doc)));
	return (CMFC1课外练习Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1课外练习View 消息处理程序


void CMFC1课外练习View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC1课外练习Doc* pDoc = GetDocument();

	CString s = pDoc->s1 + s2;
	//s.Format(__T());
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s);
	CView::OnLButtonDown(nFlags, point);
}
