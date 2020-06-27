
// MFC2实验3View.cpp: CMFC2实验3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2实验3.h"
#endif

#include "MFC2实验3Doc.h"
#include "MFC2实验3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2实验3View

IMPLEMENT_DYNCREATE(CMFC2实验3View, CView)

BEGIN_MESSAGE_MAP(CMFC2实验3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC2实验3View 构造/析构

CMFC2实验3View::CMFC2实验3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2实验3View::~CMFC2实验3View()
{
}

BOOL CMFC2实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2实验3View 绘图

void CMFC2实验3View::OnDraw(CDC* pDC)
{
	CMFC2实验3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC2实验3View 诊断

#ifdef _DEBUG
void CMFC2实验3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2实验3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2实验3Doc* CMFC2实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2实验3Doc)));
	return (CMFC2实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2实验3View 消息处理程序


void CMFC2实验3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC2实验3Doc* pDoc = GetDocument();
	pDoc->count = (pDoc->count) + 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC2实验3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC2实验3Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("左健点计了 %d 次"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s);
	CView::OnRButtonDown(nFlags, point);
}
