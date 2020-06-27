
// MFC6课堂1View.cpp: CMFC6课堂1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6课堂1.h"
#endif

#include "MFC6课堂1Doc.h"
#include "MFC6课堂1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6课堂1View

IMPLEMENT_DYNCREATE(CMFC6课堂1View, CView)

BEGIN_MESSAGE_MAP(CMFC6课堂1View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC6课堂1View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC6课堂1View 构造/析构

CMFC6课堂1View::CMFC6课堂1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC6课堂1View::~CMFC6课堂1View()
{
}

BOOL CMFC6课堂1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6课堂1View 绘图

void CMFC6课堂1View::OnDraw(CDC* /*pDC*/)
{
	CMFC6课堂1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC6课堂1View 诊断

#ifdef _DEBUG
void CMFC6课堂1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6课堂1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6课堂1Doc* CMFC6课堂1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6课堂1Doc)));
	return (CMFC6课堂1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6课堂1View 消息处理程序


void CMFC6课堂1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		CImage img;
		int w, h, sx, sy;
		CRect cr;
		GetClientRect(&cr);
		img.Load(filename);

		float cr_ratio = 1.0 * cr.Width() / cr.Height();
		float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

		if (cr_ratio > img_ratio) {
			h = cr.Height();
			w = img_ratio * h;
			sx = (cr.Width() - w) / 2;
			sy = 0;
		}
		else {
			w = cr.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (cr.Height() - h) / 2;
		}
		img.Draw(dc.m_hDC, sx, sy, w, h);
	}
}
