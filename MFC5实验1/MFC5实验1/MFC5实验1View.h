
// MFC5实验1View.h: CMFC5实验1View 类的接口
//

#pragma once


class CMFC5实验1View : public CView
{
protected: // 仅从序列化创建
	CMFC5实验1View() noexcept;
	DECLARE_DYNCREATE(CMFC5实验1View)

// 特性
public:
	CMFC5实验1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC5实验1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC5实验1View.cpp 中的调试版本
inline CMFC5实验1Doc* CMFC5实验1View::GetDocument() const
   { return reinterpret_cast<CMFC5实验1Doc*>(m_pDocument); }
#endif

