
// MFC6实验1View.h: CMFC6实验1View 类的接口
//

#pragma once


class CMFC6实验1View : public CView
{
protected: // 仅从序列化创建
	CMFC6实验1View() noexcept;
	DECLARE_DYNCREATE(CMFC6实验1View)

// 特性
public:
	CMFC6实验1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC6实验1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s;
	CRect cr;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC6实验1View.cpp 中的调试版本
inline CMFC6实验1Doc* CMFC6实验1View::GetDocument() const
   { return reinterpret_cast<CMFC6实验1Doc*>(m_pDocument); }
#endif

