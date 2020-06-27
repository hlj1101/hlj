
// 8实验2（2）View.cpp : CMy8实验2（2）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "8实验2（2）.h"
#endif

#include "8实验2（2）Doc.h"
#include "8实验2（2）View.h"
#include "MyDia0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8实验2（2）View

IMPLEMENT_DYNCREATE(CMy8实验2（2）View, CView)

BEGIN_MESSAGE_MAP(CMy8实验2（2）View, CView)
	ON_COMMAND(ID_Onput, &CMy8实验2（2）View::OnOnput)
END_MESSAGE_MAP()

// CMy8实验2（2）View 构造/析构

CMy8实验2（2）View::CMy8实验2（2）View()
{
	// TODO: 在此处添加构造代码

}

CMy8实验2（2）View::~CMy8实验2（2）View()
{
}

BOOL CMy8实验2（2）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy8实验2（2）View 绘制

void CMy8实验2（2）View::OnDraw(CDC* /*pDC*/)
{
	CMy8实验2（2）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy8实验2（2）View 诊断

#ifdef _DEBUG
void CMy8实验2（2）View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8实验2（2）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8实验2（2）Doc* CMy8实验2（2）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8实验2（2）Doc)));
	return (CMy8实验2（2）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8实验2（2）View 消息处理程序


void CMy8实验2（2）View::OnOnput()
{
	// TODO: 在此添加命令处理程序代码
	MyDia0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		int X, Y, A, B;
		X = dlg.x;
		Y= dlg.y;
		A= dlg.a;
		B= dlg.b;
		CRect cr(X - A, Y - B, X + A, Y + B);
		GetDC()->Ellipse(cr);
	}
}
