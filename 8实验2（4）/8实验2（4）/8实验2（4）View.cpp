
// 8实验2（4）View.cpp : CMy8实验2（4）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8实验2（4）.h"
#endif

#include "8实验2（4）Doc.h"
#include "8实验2（4）View.h"
#include "mydia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8实验2（4）View

IMPLEMENT_DYNCREATE(CMy8实验2（4）View, CView)

BEGIN_MESSAGE_MAP(CMy8实验2（4）View, CView)
	ON_COMMAND(ID_Menu, &CMy8实验2（4）View::OnMenu)
END_MESSAGE_MAP()

// CMy8实验2（4）View 构造/析构

CMy8实验2（4）View::CMy8实验2（4）View()
{
	// TODO: 在此处添加构造代码

}

CMy8实验2（4）View::~CMy8实验2（4）View()
{
}

BOOL CMy8实验2（4）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy8实验2（4）View 绘制

void CMy8实验2（4）View::OnDraw(CDC* pDC)
{
	CMy8实验2（4）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBrush *oldbrush, brush;
	brush.CreateSolidBrush(RGB(c1, c2, c3));
	oldbrush = pDC->SelectObject(&brush);
	pDC->Ellipse(pDoc->cr);
	pDC->SelectObject(oldbrush);
}


// CMy8实验2（4）View 诊断

#ifdef _DEBUG
void CMy8实验2（4）View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8实验2（4）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8实验2（4）Doc* CMy8实验2（4）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8实验2（4）Doc)));
	return (CMy8实验2（4）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8实验2（4）View 消息处理程序


void CMy8实验2（4）View::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	mydia dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		c1 = dlg.color1;
		c2 = dlg.color2;
		c3 = dlg.color3;
	}
	Invalidate();
}
