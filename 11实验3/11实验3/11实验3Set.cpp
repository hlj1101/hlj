
// 11实验3Set.cpp : CMy11实验3Set 类的实现
//

#include "stdafx.h"
#include "11实验3.h"
#include "11实验3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11实验3Set 实现

// 代码生成在 2020年5月15日, 22:04

IMPLEMENT_DYNAMIC(CMy11实验3Set, CRecordset)

CMy11实验3Set::CMy11实验3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = L"";
	m_4 = 0;
	m_5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMy11实验3Set::GetDefaultConnect()
{
	return _T("数据眼_11周");
}

CString CMy11实验3Set::GetDefaultSQL()
{
	return _T("[十一周]");
}

void CMy11实验3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Long(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);
	RFX_Long(pFX, _T("[字段4]"), m_4);
	RFX_Text(pFX, _T("[字段5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11实验3Set 诊断

#ifdef _DEBUG
void CMy11实验3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11实验3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

