
// MFC2实验1View.cpp: CMFC2实验1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2实验1.h"
#endif

#include "MFC2实验1Doc.h"
#include "MFC2实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2实验1View

IMPLEMENT_DYNCREATE(CMFC2实验1View, CView)

BEGIN_MESSAGE_MAP(CMFC2实验1View, CView)
END_MESSAGE_MAP()

// CMFC2实验1View 构造/析构

CMFC2实验1View::CMFC2实验1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2实验1View::~CMFC2实验1View()
{
}

BOOL CMFC2实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2实验1View 绘图

void CMFC2实验1View::OnDraw(CDC* pDC)
{
	CMFC2实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1,s2;
	int A = 123;
	s1.Format(_T("我是黄丽娟"));
	s2.Format (_T("%d"),A);
	CClientDC dc(this);
	dc.TextOutW(100, 200, s1);
	dc.TextOutW(200, 300, s2);
	
}


// CMFC2实验1View 诊断

#ifdef _DEBUG
void CMFC2实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2实验1Doc* CMFC2实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2实验1Doc)));
	return (CMFC2实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2实验1View 消息处理程序
