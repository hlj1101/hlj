
// 9课练1View.h : CMy9课练1View 类的接口
//

#pragma once


class CMy9课练1View : public CView
{
protected: // 仅从序列化创建
	CMy9课练1View();
	DECLARE_DYNCREATE(CMy9课练1View)

// 特性
public:
	CMy9课练1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy9课练1View();
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
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // 9课练1View.cpp 中的调试版本
inline CMy9课练1Doc* CMy9课练1View::GetDocument() const
   { return reinterpret_cast<CMy9课练1Doc*>(m_pDocument); }
#endif

