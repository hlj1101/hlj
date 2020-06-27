
// 8实验2（3）View.cpp : CMy8实验2（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8实验2（3）.h"
#endif

#include "8实验2（3）Doc.h"
#include "8实验2（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8实验2（3）View

IMPLEMENT_DYNCREATE(CMy8实验2（3）View, CView)

BEGIN_MESSAGE_MAP(CMy8实验2（3）View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy8实验2（3）View 构造/析构

CMy8实验2（3）View::CMy8实验2（3）View()
{
	// TODO: 在此处添加构造代码

}

CMy8实验2（3）View::~CMy8实验2（3）View()
{
}

BOOL CMy8实验2（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy8实验2（3）View 绘制

void CMy8实验2（3）View::OnDraw(CDC* pDC)
{
	CMy8实验2（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);
}


// CMy8实验2（3）View 诊断

#ifdef _DEBUG
void CMy8实验2（3）View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8实验2（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8实验2（3）Doc* CMy8实验2（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8实验2（3）Doc)));
	return (CMy8实验2（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8实验2（3）View 消息处理程序


void CMy8实验2（3）View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy8实验2（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy8实验2（3）Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->m = true;
	CPen *oldpen = NULL;
	CPen pen(PS_DASH, 1, RGB(0,0,255));
	GetDC()->SelectStockObject(NULL_BRUSH);
	CBrush *oldbrush = NULL;
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	oldbrush = dc.SelectObject(brush);
	if (point.x > pDoc->cr.left && point.x < pDoc->cr.right) {
		if (point.y > pDoc->cr.top && point.y < pDoc->cr.bottom) {
			oldpen = dc.SelectObject(&pen);
			dc.Rectangle(pDoc->cr);
			dc.SelectObject(oldpen);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy8实验2（3）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonUp(nFlags, point);
}


void CMy8实验2（3）View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnRButtonDown(nFlags, point);
}
