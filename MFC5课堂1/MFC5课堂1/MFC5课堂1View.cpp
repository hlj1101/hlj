
// MFC5课堂1View.cpp: CMFC5课堂1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5课堂1.h"
#endif

#include "MFC5课堂1Doc.h"
#include "MFC5课堂1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5课堂1View

IMPLEMENT_DYNCREATE(CMFC5课堂1View, CView)

BEGIN_MESSAGE_MAP(CMFC5课堂1View, CView)
	ON_COMMAND(ID_showellipse2, &CMFC5课堂1View::Onshowellipse2)
	ON_COMMAND(ID_showellipse1, &CMFC5课堂1View::Onshowellipse1)
END_MESSAGE_MAP()

// CMFC5课堂1View 构造/析构

CMFC5课堂1View::CMFC5课堂1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC5课堂1View::~CMFC5课堂1View()
{
}

BOOL CMFC5课堂1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5课堂1View 绘图

void CMFC5课堂1View::OnDraw(CDC* pDC)
{
	CMFC5课堂1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	/*int i,s, t = 10;
	int N = 70;
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	int y = cr.bottom - cr.top;
	int x = cr.right - cr.left;
	int red = 0, green = 0, blue = 0;
	int width = 2, row = 20;
	switch (set) {
	case 1:
		if (y <= x)
		{

			for (i = 0; i < N; i++)
			{
				t = i * 3;
				CRect cr1((x / 2 - y / 2) + t, cr.top + t, (x / 2 + y / 2) - t, cr.bottom - t);
				dc.Ellipse(cr1);
			}

		}
		if (y > x)
		{
			for (i = 0; i < N; i++)
			{
				t = i * 3;
				CRect cr1((x / 2 - y / 2) - t, cr.top - t, (x / 2 + y / 2) + t, cr.bottom + t);
				dc.Ellipse(cr1);
			}
		}

		break;
	case 2:
		if (y <= x)
		{

			for (i = 0, s = 0; i < N, s < N; i++, s++)
			{
				int color = RGB(red, green, blue);
				CPen newPen(PS_SOLID, width, color);
				//CPen *oldPen = pDC->SelectObject(newPen);
				t = i * 3;
				CRect cr1((x / 2 - y / 2) + t, cr.top + t, (x / 2 + y / 2) - t, cr.bottom - t);
				dc.Ellipse(cr1);
				//pDC->SelectObject(oldPen);
				red += 32;
				green += 16;
				blue += 8;
				width += 2;
				row += 30;
			}

		}
		if (y > x)
		{
			for (i = 0; i < N; i++)
			{
				t = i * 3;
				CRect cr1((x / 2 - y / 2) - t, cr.top - t, (x / 2 + y / 2) + t, cr.bottom + t);
				dc.Ellipse(cr1);
			}
		}
		break;

	}*/
	
}


// CMFC5课堂1View 诊断

#ifdef _DEBUG
void CMFC5课堂1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5课堂1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5课堂1Doc* CMFC5课堂1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5课堂1Doc)));
	return (CMFC5课堂1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5课堂1View 消息处理程序


void CMFC5课堂1View::Onshowellipse2()
{
	// TODO: 在此添加命令处理程序代码
	CMFC5课堂1Doc* pDoc = GetDocument();
	//set = 2;
	/*int i,s, t = 10;
	int N = 70;
	//int M = 8;
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	int y = cr.bottom - cr.top;
	int x = cr.right - cr.left;
	int red = 0, green = 0, blue = 0;
	int width = 2, row = 20;
	CClientDC dc(this);
	if (y <= x)
	{

		for (i = 0,s=0; i < N,s<N; i++,s++)
		{
			int color = RGB(red, green, blue);
			CPen newPen(PS_SOLID, width, color);
			CPen* oldPen = SelectObject(newPen);
			t = i * 3;
			CRect cr1((x / 2 - y / 2) + t, cr.top + t, (x / 2 + y / 2) - t, cr.bottom - t);
			dc.Ellipse(cr1);
			pDC->SelectObject(oldPen);
			red += 32;
			green += 16;
			blue += 8;
			width += 2;
			row += 30;
		}

	}
	if (y > x)
	{
		for (i = 0; i < N; i++)
		{
			t = i * 3;
			CRect cr1((x / 2 - y / 2) - t, cr.top - t, (x / 2 + y / 2) + t, cr.bottom + t);
			dc.Ellipse(cr1);
		}
	}*/
}


void CMFC5课堂1View::Onshowellipse1()
{
	// TODO: 在此添加命令处理程序代码
	CMFC5课堂1Doc* pDoc = GetDocument();
	set = 1;
	int i, t = 10;
	int N = 70;
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	int y = cr.bottom - cr.top;
	int x = cr.right - cr.left;
	if (y <= x)
	{
		
			for (i = 0; i < N; i++)
			{
				t = i * 3;
				CRect cr1((x / 2 - y / 2)+t, cr.top+t, (x / 2 + y / 2)-t, cr.bottom-t);
				dc.Ellipse(cr1);
			}
		
	}
	if (y > x)
	{
		for (i = 0; i < N; i++)
		{
			t = i * 3;
			CRect cr1((x / 2 - y / 2) -t, cr.top - t, (x / 2 + y / 2) +t, cr.bottom + t);
			dc.Ellipse(cr1);
		}
	}
}
