
// MFC3课堂1View.cpp: CMFC3课堂1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3课堂1.h"
#endif

#include "MFC3课堂1Doc.h"
#include "MFC3课堂1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3课堂1View

IMPLEMENT_DYNCREATE(CMFC3课堂1View, CView)

BEGIN_MESSAGE_MAP(CMFC3课堂1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3课堂1View 构造/析构

CMFC3课堂1View::CMFC3课堂1View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

CMFC3课堂1View::~CMFC3课堂1View()
{
}

BOOL CMFC3课堂1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3课堂1View 绘图

void CMFC3课堂1View::OnDraw(CDC* pDC)
{
	CMFC3课堂1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3课堂1View 诊断

#ifdef _DEBUG
void CMFC3课堂1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3课堂1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3课堂1Doc* CMFC3课堂1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3课堂1Doc)));
	return (CMFC3课堂1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3课堂1View 消息处理程序


void CMFC3课堂1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3课堂1Doc* pDoc = GetDocument();
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	int y = cr.bottom - cr.top;
	int x = cr.right - cr.left;
	if (y <= x)
	{
		
			CRect cr1(x / 2 - y / 2, cr.top, x / 2 + y / 2 , cr.bottom);

			dc.Ellipse(cr1);
	}
	if (y > x)
	{

			CRect cr1(cr.left, y / 2 - x / 2, cr.right, y / 2 + x / 2);
			
			dc.Ellipse(cr1);
			
	}
	//this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
