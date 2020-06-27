
// 综合实验1View.cpp : C综合实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验1.h"
#endif

#include "综合实验1Set.h"
#include "综合实验1Doc.h"
#include "综合实验1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验1View

IMPLEMENT_DYNCREATE(C综合实验1View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验1View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C综合实验1View 构造/析构

C综合实验1View::C综合实验1View()
	: CRecordView(IDD_MY1_FORM)
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\myvcshiyan\\hhbby\\ABC\\");

}

C综合实验1View::~C综合实验1View()
{
}

void C综合实验1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验1Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验1View 诊断

#ifdef _DEBUG
void C综合实验1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验1Doc* C综合实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验1Doc)));
	return (C综合实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验1View 数据库支持
CRecordset* C综合实验1View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验1View 消息处理程序


void C综合实验1View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	//CClientDC dc(this);
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void C综合实验1View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void C综合实验1View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void C综合实验1View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}

void C综合实验1View::draw_Pic(CString file)
{
	//IDC_STATIC
	
}


void C综合实验1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, m_pSet->m_1);
	filename = path + m_pSet->m_1;
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	//InvalidateRect(rect);
	ReleaseDC(pDC);
	
}
