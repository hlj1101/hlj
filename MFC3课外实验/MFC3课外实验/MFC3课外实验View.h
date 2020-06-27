
// MFC3课外实验View.h: CMFC3课外实验View 类的接口
//

#pragma once


class CMFC3课外实验View : public CView
{
protected: // 仅从序列化创建
	CMFC3课外实验View() noexcept;
	DECLARE_DYNCREATE(CMFC3课外实验View)

// 特性
public:
	CMFC3课外实验Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3课外实验View();
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

#ifndef _DEBUG  // MFC3课外实验View.cpp 中的调试版本
inline CMFC3课外实验Doc* CMFC3课外实验View::GetDocument() const
   { return reinterpret_cast<CMFC3课外实验Doc*>(m_pDocument); }
#endif

