
// USingW32DllView.h : CUSingW32DllView 类的接口
//

#pragma once


class CUSingW32DllView : public CView
{
protected: // 仅从序列化创建
	CUSingW32DllView();
	DECLARE_DYNCREATE(CUSingW32DllView)

// 特性
public:
	CUSingW32DllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUSingW32DllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // USingW32DllView.cpp 中的调试版本
inline CUSingW32DllDoc* CUSingW32DllView::GetDocument() const
   { return reinterpret_cast<CUSingW32DllDoc*>(m_pDocument); }
#endif

