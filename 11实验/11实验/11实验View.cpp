
// 11实验View.cpp : CMy11实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11实验.h"
#endif

#include "11实验Set.h"
#include "11实验Doc.h"
#include "11实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11实验View

IMPLEMENT_DYNCREATE(CMy11实验View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11实验View, CRecordView)
END_MESSAGE_MAP()

// CMy11实验View 构造/析构

CMy11实验View::CMy11实验View()
	: CRecordView(IDD_MY11_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMy11实验View::~CMy11实验View()
{
}

void CMy11实验View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CMy11实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11实验Set;
	CRecordView::OnInitialUpdate();

}


// CMy11实验View 诊断

#ifdef _DEBUG
void CMy11实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11实验Doc* CMy11实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11实验Doc)));
	return (CMy11实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11实验View 数据库支持
CRecordset* CMy11实验View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11实验View 消息处理程序
