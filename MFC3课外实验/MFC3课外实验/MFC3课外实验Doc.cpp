
// MFC3课外实验Doc.cpp: CMFC3课外实验Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3课外实验.h"
#endif

#include "MFC3课外实验Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC3课外实验Doc

IMPLEMENT_DYNCREATE(CMFC3课外实验Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC3课外实验Doc, CDocument)
END_MESSAGE_MAP()


// CMFC3课外实验Doc 构造/析构

CMFC3课外实验Doc::CMFC3课外实验Doc() noexcept
{
	// TODO: 在此添加一次性构造代码
	cr1.left = 20, cr1.top = 100, cr1.right = 200, cr1.bottom = 200;
	cr2.left = 220, cr2.top = 100, cr2.right = 400, cr2.bottom = 200;
	cr3.left = 420, cr3.top = 100, cr3.right = 600, cr3.bottom = 200;
	cr4.left = 620, cr4.top = 100, cr4.right = 800, cr4.bottom = 200;
}

CMFC3课外实验Doc::~CMFC3课外实验Doc()
{
}

BOOL CMFC3课外实验Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC3课外实验Doc 序列化

void CMFC3课外实验Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC3课外实验Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFC3课外实验Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC3课外实验Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC3课外实验Doc 诊断

#ifdef _DEBUG
void CMFC3课外实验Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC3课外实验Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC3课外实验Doc 命令
