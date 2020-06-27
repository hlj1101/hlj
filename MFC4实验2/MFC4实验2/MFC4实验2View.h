
// MFC4实验2View.h: CMFC4实验2View 类的接口
//

#pragma once


class CMFC4实验2View : public CView
{
protected: // 仅从序列化创建
	CMFC4实验2View() noexcept;
	DECLARE_DYNCREATE(CMFC4实验2View)

// 特性
public:
	CMFC4实验2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4实验2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4实验2View.cpp 中的调试版本
inline CMFC4实验2Doc* CMFC4实验2View::GetDocument() const
   { return reinterpret_cast<CMFC4实验2Doc*>(m_pDocument); }
#endif

