
// 10实验View.cpp : CMy10实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "10实验.h"
#endif

#include "10实验Doc.h"
#include "10实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10实验View

IMPLEMENT_DYNCREATE(CMy10实验View, CView)

BEGIN_MESSAGE_MAP(CMy10实验View, CView)
END_MESSAGE_MAP()

// CMy10实验View 构造/析构

CMy10实验View::CMy10实验View()
{
	// TODO: 在此处添加构造代码

}

CMy10实验View::~CMy10实验View()
{
}

BOOL CMy10实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy10实验View 绘制

void CMy10实验View::OnDraw(CDC* /*pDC*/)
{
	CMy10实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy10实验View 诊断

#ifdef _DEBUG
void CMy10实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy10实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10实验Doc* CMy10实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10实验Doc)));
	return (CMy10实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10实验View 消息处理程序
