
// MFC6课堂1View.h: CMFC6课堂1View 类的接口
//

#pragma once


class CMFC6课堂1View : public CView
{
protected: // 仅从序列化创建
	CMFC6课堂1View() noexcept;
	DECLARE_DYNCREATE(CMFC6课堂1View)

// 特性
public:
	CMFC6课堂1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC6课堂1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC6课堂1View.cpp 中的调试版本
inline CMFC6课堂1Doc* CMFC6课堂1View::GetDocument() const
   { return reinterpret_cast<CMFC6课堂1Doc*>(m_pDocument); }
#endif

