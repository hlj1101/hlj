
// MFC3实验1View.cpp: CMFC3实验1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3实验1.h"
#endif

#include "MFC3实验1Doc.h"
#include "MFC3实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3实验1View

IMPLEMENT_DYNCREATE(CMFC3实验1View, CView)

BEGIN_MESSAGE_MAP(CMFC3实验1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3实验1View 构造/析构

CMFC3实验1View::CMFC3实验1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3实验1View::~CMFC3实验1View()
{
}

BOOL CMFC3实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3实验1View 绘图

void CMFC3实验1View::OnDraw(CDC* pDC)
{
	CMFC3实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3实验1View 诊断

#ifdef _DEBUG
void CMFC3实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3实验1Doc* CMFC3实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3实验1Doc)));
	return (CMFC3实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3实验1View 消息处理程序


void CMFC3实验1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左健正在被按下"));
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3实验1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左健正在被抬起"));
	CClientDC dc(this);
	dc.TextOutW(point.x + 30, point.y + 30, s);
	CView::OnLButtonUp(nFlags, point);
}
