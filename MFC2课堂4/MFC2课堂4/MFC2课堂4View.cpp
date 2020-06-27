
// MFC2课堂4View.cpp: CMFC2课堂4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2课堂4.h"
#endif

#include "MFC2课堂4Doc.h"
#include "MFC2课堂4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2课堂4View

IMPLEMENT_DYNCREATE(CMFC2课堂4View, CView)

BEGIN_MESSAGE_MAP(CMFC2课堂4View, CView)
END_MESSAGE_MAP()

// CMFC2课堂4View 构造/析构

CMFC2课堂4View::CMFC2课堂4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2课堂4View::~CMFC2课堂4View()
{
}

BOOL CMFC2课堂4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2课堂4View 绘图

void CMFC2课堂4View::OnDraw(CDC* pDC)
{
	CMFC2课堂4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(&cr);
	CBrush newBrush((COLORREF)0x0000FF00);
	CBrush* oldBrush = pDC->SelectObject(&newBrush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldBrush);
}


// CMFC2课堂4View 诊断

#ifdef _DEBUG
void CMFC2课堂4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2课堂4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2课堂4Doc* CMFC2课堂4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2课堂4Doc)));
	return (CMFC2课堂4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2课堂4View 消息处理程序
