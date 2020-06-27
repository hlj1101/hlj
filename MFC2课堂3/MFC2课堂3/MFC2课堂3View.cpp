
// MFC2课堂3View.cpp: CMFC2课堂3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2课堂3.h"
#endif

#include "MFC2课堂3Doc.h"
#include "MFC2课堂3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2课堂3View

IMPLEMENT_DYNCREATE(CMFC2课堂3View, CView)

BEGIN_MESSAGE_MAP(CMFC2课堂3View, CView)
END_MESSAGE_MAP()

// CMFC2课堂3View 构造/析构

CMFC2课堂3View::CMFC2课堂3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2课堂3View::~CMFC2课堂3View()
{
}

BOOL CMFC2课堂3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2课堂3View 绘图

void CMFC2课堂3View::OnDraw(CDC* pDC)
{
	CMFC2课堂3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(cr);
	CClientDC dc(this);
	dc.Ellipse(cr);
}


// CMFC2课堂3View 诊断

#ifdef _DEBUG
void CMFC2课堂3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2课堂3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2课堂3Doc* CMFC2课堂3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2课堂3Doc)));
	return (CMFC2课堂3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2课堂3View 消息处理程序
