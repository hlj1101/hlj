
// MFC4实验3View.cpp: CMFC4实验3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4实验3.h"
#endif

#include "MFC4实验3Doc.h"
#include "MFC4实验3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4实验3View

IMPLEMENT_DYNCREATE(CMFC4实验3View, CView)

BEGIN_MESSAGE_MAP(CMFC4实验3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC4实验3View 构造/析构

CMFC4实验3View::CMFC4实验3View() noexcept
{
	// TODO: 在此处添加构造代码
	cr.left = 100; cr.top = 0; cr.right = 150; cr.bottom = 50;
	set = true;
	flag = 1;
}

CMFC4实验3View::~CMFC4实验3View()
{
}

BOOL CMFC4实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4实验3View 绘图

void CMFC4实验3View::OnDraw(CDC* pDC)
{
	CMFC4实验3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
	if (set) {
		SetTimer(0, 100, NULL);
		set = false;
	}
}


// CMFC4实验3View 诊断

#ifdef _DEBUG
void CMFC4实验3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4实验3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4实验3Doc* CMFC4实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4实验3Doc)));
	return (CMFC4实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4实验3View 消息处理程序


void CMFC4实验3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4实验3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC4实验3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4实验3Doc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);
	int i = nIDEvent;
	if (cr.bottom>=rect.bottom)
	{
		flag = 0;
	}
	if(flag==1){
		cr.top += 10;
		cr.bottom += 10;
	}
	else {
		cr.top -= 10;
		cr.bottom -= 10;
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}
