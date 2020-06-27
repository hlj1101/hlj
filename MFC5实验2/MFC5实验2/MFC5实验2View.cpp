
// MFC5实验2View.cpp: CMFC5实验2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5实验2.h"
#endif

#include "MFC5实验2Doc.h"
#include "MFC5实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5实验2View

IMPLEMENT_DYNCREATE(CMFC5实验2View, CView)

BEGIN_MESSAGE_MAP(CMFC5实验2View, CView)
END_MESSAGE_MAP()

// CMFC5实验2View 构造/析构

CMFC5实验2View::CMFC5实验2View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFC5实验2View::~CMFC5实验2View()
{
}

BOOL CMFC5实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5实验2View 绘图

void CMFC5实验2View::OnDraw(CDC* pDC)
{
	CMFC5实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMFC5实验2View 诊断

#ifdef _DEBUG
void CMFC5实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5实验2Doc* CMFC5实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5实验2Doc)));
	return (CMFC5实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5实验2View 消息处理程序
