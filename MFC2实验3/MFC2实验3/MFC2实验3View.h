
// MFC2实验3View.h: CMFC2实验3View 类的接口
//

#pragma once


class CMFC2实验3View : public CView
{
protected: // 仅从序列化创建
	CMFC2实验3View() noexcept;
	DECLARE_DYNCREATE(CMFC2实验3View)

// 特性
public:
	CMFC2实验3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC2实验3View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC2实验3View.cpp 中的调试版本
inline CMFC2实验3Doc* CMFC2实验3View::GetDocument() const
   { return reinterpret_cast<CMFC2实验3Doc*>(m_pDocument); }
#endif

