
// MFC4实验2View.cpp: CMFC4实验2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4实验2.h"
#endif

#include "MFC4实验2Doc.h"
#include "MFC4实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4实验2View

IMPLEMENT_DYNCREATE(CMFC4实验2View, CView)

BEGIN_MESSAGE_MAP(CMFC4实验2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC4实验2View 构造/析构

CMFC4实验2View::CMFC4实验2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4实验2View::~CMFC4实验2View()
{
}

BOOL CMFC4实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4实验2View 绘图

void CMFC4实验2View::OnDraw(CDC* pDC)
{
	CMFC4实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
}


// CMFC4实验2View 诊断

#ifdef _DEBUG
void CMFC4实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4实验2Doc* CMFC4实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4实验2Doc)));
	return (CMFC4实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4实验2View 消息处理程序


void CMFC4实验2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4实验2Doc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left > 0) {
			pDoc->cr.left -= 5;
			pDoc->cr.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right <= rect.right - rect.left) {
			pDoc->cr.left += 5;
			pDoc->cr.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom <= rect.bottom - rect.top) {
			pDoc->cr.top += 5;
			pDoc->cr.bottom += 5;
		}
		break;
	case VK_UP:
		if (pDoc->cr.top > 0) {
			pDoc->cr.top -= 5;
			pDoc->cr.bottom -= 5;
		}
		break;
	case VK_HOME:
		if (pDoc->cr.left > 0) {
			pDoc->cr.left -= 20;
			pDoc->cr.top -= 20;
		}
		break;
	case VK_END:
		if (pDoc->cr.right <= rect.right - rect.left) {
			pDoc->cr.right -= 20;
			pDoc->cr.bottom -= 20;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC4实验2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4实验2Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->cr.left = 400;
	pDoc->cr.top = 200;
	pDoc->cr.right = 500;
	pDoc->cr.bottom = 300;
	dc.Rectangle(pDoc->cr);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
