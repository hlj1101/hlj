
// MFC5实验3View.h: CMFC5实验3View 类的接口
//

#pragma once


class CMFC5实验3View : public CView
{
protected: // 仅从序列化创建
	CMFC5实验3View() noexcept;
	DECLARE_DYNCREATE(CMFC5实验3View)

// 特性
public:
	CMFC5实验3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC5实验3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int set;
	int A, B, C, D;
	CRect cr;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Online();
	afx_msg void Onrectangle();
	afx_msg void Oncrect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC5实验3View.cpp 中的调试版本
inline CMFC5实验3Doc* CMFC5实验3View::GetDocument() const
   { return reinterpret_cast<CMFC5实验3Doc*>(m_pDocument); }
#endif

