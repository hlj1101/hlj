
// MFC2实验2View.cpp: CMFC2实验2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2实验2.h"
#endif

#include "MFC2实验2Doc.h"
#include "MFC2实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2实验2View

IMPLEMENT_DYNCREATE(CMFC2实验2View, CView)

BEGIN_MESSAGE_MAP(CMFC2实验2View, CView)
END_MESSAGE_MAP()

// CMFC2实验2View 构造/析构

CMFC2实验2View::CMFC2实验2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2实验2View::~CMFC2实验2View()
{
}

BOOL CMFC2实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2实验2View 绘图

void CMFC2实验2View::OnDraw(CDC* pDC)
{
	CMFC2实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s2;
	s2.Format(_T("%d"), pDoc->A);
	CClientDC dc(this);
	dc.TextOutW(100, 200, pDoc->s);
	dc.TextOutW(200, 300, s2);
}


// CMFC2实验2View 诊断

#ifdef _DEBUG
void CMFC2实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2实验2Doc* CMFC2实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2实验2Doc)));
	return (CMFC2实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2实验2View 消息处理程序
