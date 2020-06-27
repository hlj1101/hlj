
// 8实验1View.cpp : CMy8实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8实验1.h"
#endif

#include "8实验1Doc.h"
#include "8实验1View.h"
#include "MyDia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8实验1View

IMPLEMENT_DYNCREATE(CMy8实验1View, CView)

BEGIN_MESSAGE_MAP(CMy8实验1View, CView)
	ON_COMMAND(ID_OnPut, &CMy8实验1View::OnOnput)
END_MESSAGE_MAP()

// CMy8实验1View 构造/析构

CMy8实验1View::CMy8实验1View()
{
	// TODO: 在此处添加构造代码

}

CMy8实验1View::~CMy8实验1View()
{
}

BOOL CMy8实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy8实验1View 绘制

void CMy8实验1View::OnDraw(CDC* /*pDC*/)
{
	CMy8实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy8实验1View 诊断

#ifdef _DEBUG
void CMy8实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8实验1Doc* CMy8实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8实验1Doc)));
	return (CMy8实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8实验1View 消息处理程序


void CMy8实验1View::OnOnput()
{
	// TODO: 在此添加命令处理程序代码
	MyDia dlg;
	int t = dlg.DoModal();
}
