
// 8实验2（3）View.h : CMy8实验2（3）View 类的接口
//

#pragma once


class CMy8实验2（3）View : public CView
{
protected: // 仅从序列化创建
	CMy8实验2（3）View();
	DECLARE_DYNCREATE(CMy8实验2（3）View)

// 特性
public:
	CMy8实验2（3）Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy8实验2（3）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 8实验2（3）View.cpp 中的调试版本
inline CMy8实验2（3）Doc* CMy8实验2（3）View::GetDocument() const
   { return reinterpret_cast<CMy8实验2（3）Doc*>(m_pDocument); }
#endif

