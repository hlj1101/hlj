
// 11实验12View.cpp : CMy11实验12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11实验12.h"
#endif

#include "11实验12Set.h"
#include "11实验12Doc.h"
#include "11实验12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11实验12View

IMPLEMENT_DYNCREATE(CMy11实验12View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11实验12View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT4, &CMy11实验12View::OnEnChangeEdit4)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11实验12View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11实验12View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11实验12View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11实验12View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11实验12View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy11实验12View 构造/析构

CMy11实验12View::CMy11实验12View()
	: CRecordView(IDD_MY1112_FORM)
	, Number(0)
	, name(_T(""))
	, age(0)
	, xingb(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMy11实验12View::~CMy11实验12View()
{
}

void CMy11实验12View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_5);
}

BOOL CMy11实验12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11实验12View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11实验12Set;
	CRecordView::OnInitialUpdate();

}


// CMy11实验12View 诊断

#ifdef _DEBUG
void CMy11实验12View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11实验12View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11实验12Doc* CMy11实验12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11实验12Doc)));
	return (CMy11实验12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11实验12View 数据库支持
CRecordset* CMy11实验12View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11实验12View 消息处理程序


void CMy11实验12View::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy11实验12View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(TRUE);
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	InvalidateRect(cr);
}


void CMy11实验12View::OnRecordPrev()
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


void CMy11实验12View::OnRecordNext()
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


void CMy11实验12View::OnRecordLast()
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


void CMy11实验12View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	filename=m_pSet->m_1;
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
