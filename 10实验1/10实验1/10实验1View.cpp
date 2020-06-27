
// 10实验1View.cpp : CMy10实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "10实验1.h"
#endif

#include "10实验1Doc.h"
#include "10实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10实验1View

IMPLEMENT_DYNCREATE(CMy10实验1View, CView)

BEGIN_MESSAGE_MAP(CMy10实验1View, CView)
END_MESSAGE_MAP()

// CMy10实验1View 构造/析构

CMy10实验1View::CMy10实验1View()
{
	// TODO: 在此处添加构造代码

}

CMy10实验1View::~CMy10实验1View()
{
}

BOOL CMy10实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy10实验1View 绘制

void CMy10实验1View::OnDraw(CDC* /*pDC*/)
{
	CMy10实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy10实验1View 诊断

#ifdef _DEBUG
void CMy10实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy10实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10实验1Doc* CMy10实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10实验1Doc)));
	return (CMy10实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10实验1View 消息处理程序
