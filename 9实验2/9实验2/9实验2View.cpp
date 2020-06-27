
// 9实验2View.cpp : CMy9实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "9实验2.h"
#endif

#include "9实验2Doc.h"
#include "9实验2View.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9实验2View

IMPLEMENT_DYNCREATE(CMy9实验2View, CView)

BEGIN_MESSAGE_MAP(CMy9实验2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMy9实验2View::OnFileOpen)
END_MESSAGE_MAP()

// CMy9实验2View 构造/析构
int flag;
CMy9实验2View::CMy9实验2View()
{
	// TODO: 在此处添加构造代码

}

CMy9实验2View::~CMy9实验2View()
{
}

BOOL CMy9实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy9实验2View 绘制

void CMy9实验2View::OnDraw(CDC* pDC)
{
	CMy9实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
	if (n != 0) {
		CString filename = _T("C:\\Users\\AUSU\\Desktop\\ellipse.txt");
		ofstream of(filename);
		for (int i = 0;i < n;i++) {
			pDC->Ellipse(a[i]);
			of << a[i].left << ' ' << a[i].top << ' ' << a[i].right << ' ' << a[i].bottom << endl;
		}
	}
}


// CMy9实验2View 诊断

#ifdef _DEBUG
void CMy9实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9实验2Doc* CMy9实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9实验2Doc)));
	return (CMy9实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9实验2View 消息处理程序


void CMy9实验2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMy9实验2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	{
		cr.right = point.x;
		cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy9实验2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	a.Add(cr);
	n++;
	CView::OnLButtonUp(nFlags, point);
}


void CMy9实验2View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString filename = _T("C:\\Users\\AUSU\\Desktop\\ellipse.txt");
	ifstream ifs(filename);
	string s;
	int count = 0, i = 0;
	int num[4];
	while (ifs >> s)
	{
		num[i] = atoi(s.c_str());
		i++;
		count++;
		if (count % 4 == 0)
		{
			CRect cr(num[0], num[1], num[2], num[3]);
			dc.Ellipse(cr);
			i = 0;
		}
	}
}
