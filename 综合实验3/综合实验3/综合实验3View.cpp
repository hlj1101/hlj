
// 综合实验3View.cpp : C综合实验3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验3.h"
#endif

#include "综合实验3Set.h"
#include "综合实验3Doc.h"
#include "综合实验3View.h"
#include "MyDia.h"
#include "MyDi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验3View

IMPLEMENT_DYNCREATE(C综合实验3View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验3View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &C综合实验3View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验3View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验3View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON2, &C综合实验3View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C综合实验3View 构造/析构

C综合实验3View::C综合实验3View()
	: CRecordView(IDD_MY3_FORM)
	, ll(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验3View::~C综合实验3View()
{
}

void C综合实验3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验3Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验3View 诊断

#ifdef _DEBUG
void C综合实验3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验3Doc* C综合实验3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验3Doc)));
	return (C综合实验3Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验3View 数据库支持
CRecordset* C综合实验3View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验3View 消息处理程序


void C综合实验3View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C综合实验3View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDia dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		long y = dlg.lo;
		m_pSet->AddNew();
		m_pSet->m_1 = y;
		m_pSet->Update();
		UpdateData(false);
	}
	
}


void C综合实验3View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void C综合实验3View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C综合实验3View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
}


void C综合实验3View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
}


void C综合实验3View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ch = m_pSet->m_1;
	MyDi dia;
	int t = dia.DoModal();
	if (t == IDOK) {
		long gg= dia.lon;
		m_pSet->Edit();
		m_pSet->m_1 = gg;
		m_pSet->Update();
		UpdateData(false);
	}
}
