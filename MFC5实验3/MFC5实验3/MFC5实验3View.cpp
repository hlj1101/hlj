
// MFC5实验3View.cpp: CMFC5实验3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5实验3.h"
#endif

#include "MFC5实验3Doc.h"
#include "MFC5实验3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5实验3View

IMPLEMENT_DYNCREATE(CMFC5实验3View, CView)

BEGIN_MESSAGE_MAP(CMFC5实验3View, CView)
	ON_COMMAND(ID_line, &CMFC5实验3View::Online)
	ON_COMMAND(ID_rectangle, &CMFC5实验3View::Onrectangle)
	ON_COMMAND(ID_crect, &CMFC5实验3View::Oncrect)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC5实验3View 构造/析构

CMFC5实验3View::CMFC5实验3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC5实验3View::~CMFC5实验3View()
{
}

BOOL CMFC5实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5实验3View 绘图

void CMFC5实验3View::OnDraw(CDC* pDC)
{
	CMFC5实验3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC5实验3View 诊断

#ifdef _DEBUG
void CMFC5实验3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5实验3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5实验3Doc* CMFC5实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5实验3Doc)));
	return (CMFC5实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5实验3View 消息处理程序


void CMFC5实验3View::Online()
{
	// TODO: 在此添加命令处理程序代码
	set = 1;
}


void CMFC5实验3View::Onrectangle()
{
	// TODO: 在此添加命令处理程序代码
	set = 2;
}


void CMFC5实验3View::Oncrect()
{
	// TODO: 在此添加命令处理程序代码
	set = 3;
}


void CMFC5实验3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC5实验3Doc* pDoc = GetDocument();
	SetCapture();
	A = point.x;
	B = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC5实验3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC5实验3Doc* pDoc = GetDocument();
	CView::OnMouseMove(nFlags, point);
}


void CMFC5实验3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC5实验3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	C= point.x;
	D = point.y;
	switch (set) {
	case 1:
		dc.MoveTo(C, D);
		dc.LineTo(A, B);
		break;
	case 2:
		cr.left = A;
		cr.top = B;
		cr.right = C;
		cr.bottom = D;
		dc.Rectangle(cr);
		break;
	case 3:
		cr.left = A;
		cr.top = B;
		cr.right = C;
		cr.bottom = D;
		dc.Ellipse(cr);
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
