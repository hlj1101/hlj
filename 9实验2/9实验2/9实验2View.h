
// 9实验2View.h : CMy9实验2View 类的接口
//

#pragma once


class CMy9实验2View : public CView
{
protected: // 仅从序列化创建
	CMy9实验2View();
	DECLARE_DYNCREATE(CMy9实验2View)

// 特性
public:
	CMy9实验2Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int n;
	CArray<CRect,CRect> a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy9实验2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 9实验2View.cpp 中的调试版本
inline CMy9实验2Doc* CMy9实验2View::GetDocument() const
   { return reinterpret_cast<CMy9实验2Doc*>(m_pDocument); }
#endif

