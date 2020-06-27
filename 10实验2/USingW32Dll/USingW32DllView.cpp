
// USingW32DllView.cpp : CUSingW32DllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "USingW32Dll.h"
#endif

#include "USingW32DllDoc.h"
#include "USingW32DllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "wh.h"

// CUSingW32DllView

IMPLEMENT_DYNCREATE(CUSingW32DllView, CView)

BEGIN_MESSAGE_MAP(CUSingW32DllView, CView)
END_MESSAGE_MAP()

// CUSingW32DllView 构造/析构

CUSingW32DllView::CUSingW32DllView()
{
	// TODO: 在此处添加构造代码

}

CUSingW32DllView::~CUSingW32DllView()
{
}

BOOL CUSingW32DllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUSingW32DllView 绘制

void CUSingW32DllView::OnDraw(CDC* pDC)
{
	CUSingW32DllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	FAC A ;
	CString s, ss;
	s = CString(pchar());
	pDC->TextOutW(100, 100, s);
	ss.Format(_T("%f"),A.convert(30.0));
	pDC->TextOutW(300, 100, ss);
}


// CUSingW32DllView 诊断

#ifdef _DEBUG
void CUSingW32DllView::AssertValid() const
{
	CView::AssertValid();
}

void CUSingW32DllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUSingW32DllDoc* CUSingW32DllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUSingW32DllDoc)));
	return (CUSingW32DllDoc*)m_pDocument;
}
#endif //_DEBUG


// CUSingW32DllView 消息处理程序
