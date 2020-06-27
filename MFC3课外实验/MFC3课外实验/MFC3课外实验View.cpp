
// MFC3课外实验View.cpp: CMFC3课外实验View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3课外实验.h"
#endif

#include "MFC3课外实验Doc.h"
#include "MFC3课外实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3课外实验View

IMPLEMENT_DYNCREATE(CMFC3课外实验View, CView)

BEGIN_MESSAGE_MAP(CMFC3课外实验View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3课外实验View 构造/析构

CMFC3课外实验View::CMFC3课外实验View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3课外实验View::~CMFC3课外实验View()
{
}

BOOL CMFC3课外实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3课外实验View 绘图

void CMFC3课外实验View::OnDraw(CDC* pDC)
{
	CMFC3课外实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr1);
	pDC->Rectangle(pDoc->cr2);
	pDC->Rectangle(pDoc->cr3);
	pDC->Rectangle(pDoc->cr4);
}


// CMFC3课外实验View 诊断

#ifdef _DEBUG
void CMFC3课外实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3课外实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3课外实验Doc* CMFC3课外实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3课外实验Doc)));
	return (CMFC3课外实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3课外实验View 消息处理程序


void CMFC3课外实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3课外实验Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->ans = pDoc->ans++;
	int r = rand() % 50 + 100;
	CString s,s2;
	s2 = (_T("点击无效"));
	if (point.x > 20 && point.x < 200 && point.y>100 && point.y < 200) {
		pDoc->a = r;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x > 220 && point.x < 400 && point.y>100 && point.y < 200) {
		pDoc->b = r;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x > 620 && point.x < 800 && point.y>100 && point.y < 200) {
		if (pDoc->ans % 4 == 3) { s.Format(_T("+")); dc.TextOutW(point.x, point.y, s); }
		if (pDoc->ans % 4 == 2) { s.Format(_T("/")); dc.TextOutW(point.x, point.y, s); }
		if (pDoc->ans % 4 == 1) { s.Format(_T("*")); dc.TextOutW(point.x, point.y, s); }
		if (pDoc->ans % 4 == 0) { s.Format(_T("-")); dc.TextOutW(point.x, point.y, s); }

	}
	else
		dc.TextOutW(point.x, point.y, s2);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3课外实验View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3课外实验Doc* pDoc = GetDocument();
	CClientDC dc(this);
	int count = 0;
	int s1, s2, s3, s4;
	CString ce;
	if (nFlags)
		count = count++;
	if (point.x > 420 && point.x < 600 && point.y>100 && point.y < 200) {
		if (count % 4 == 1) {
			s1 = pDoc->a + pDoc->b;
			ce.Format(_T("%d"), s1);
			dc.TextOutW(point.x, point.y, ce);
		}
		else if (count % 4 == 2) {
			s2 = pDoc->a - pDoc->b;
			ce.Format(_T("%d"), s2);
			dc.TextOutW(point.x, point.y, ce);
		}
		else if (count % 4 == 3) {
			s3 = pDoc->a * pDoc->b;
			ce.Format(_T("%d"), s3);
			dc.TextOutW(point.x, point.y, ce);
		}
		else if (count % 4 == 4 || count % 4 == 0) {
			s4 = pDoc->a / pDoc->b;
			ce.Format(_T("%d"), s4);
			dc.TextOutW(point.x, point.y, ce);
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
