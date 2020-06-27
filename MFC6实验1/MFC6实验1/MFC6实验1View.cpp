
// MFC6实验1View.cpp: CMFC6实验1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6实验1.h"
#endif

#include "MFC6实验1Doc.h"
#include "MFC6实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6实验1View

IMPLEMENT_DYNCREATE(CMFC6实验1View, CView)

BEGIN_MESSAGE_MAP(CMFC6实验1View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC6实验1View 构造/析构

CMFC6实验1View::CMFC6实验1View() noexcept
{
	// TODO: 在此处添加构造代码
	s = "";
	cr.left = 30;
	cr.top = 30;
	cr.right = 300; 
	cr.bottom = 300;
}

CMFC6实验1View::~CMFC6实验1View()
{
}

BOOL CMFC6实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6实验1View 绘图

void CMFC6实验1View::OnDraw(CDC* pDC)
{
	CMFC6实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(&cr);
}


// CMFC6实验1View 诊断

#ifdef _DEBUG
void CMFC6实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6实验1Doc* CMFC6实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6实验1Doc)));
	return (CMFC6实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6实验1View 消息处理程序


void CMFC6实验1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	s = s + (char)nChar;
	dc.TextOutW(cr.left + 10, cr.top + 10, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
