
// MFC例子View.cpp: CMFC例子View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC例子.h"
#endif

#include "MFC例子Doc.h"
#include "MFC例子View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC例子View

IMPLEMENT_DYNCREATE(CMFC例子View, CView)

BEGIN_MESSAGE_MAP(CMFC例子View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC例子View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC例子View 构造/析构

CMFC例子View::CMFC例子View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC例子View::~CMFC例子View()
{
}

BOOL CMFC例子View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC例子View 绘图

void CMFC例子View::OnDraw(CDC* /*pDC*/)
{
	CMFC例子Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC例子View 打印


void CMFC例子View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC例子View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC例子View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC例子View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFC例子View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC例子View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC例子View 诊断

#ifdef _DEBUG
void CMFC例子View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC例子View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC例子Doc* CMFC例子View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC例子Doc)));
	return (CMFC例子Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC例子View 消息处理程序
