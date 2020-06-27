
// MFC2实验2View.h: CMFC2实验2View 类的接口
//

#pragma once


class CMFC2实验2View : public CView
{
protected: // 仅从序列化创建
	CMFC2实验2View() noexcept;
	DECLARE_DYNCREATE(CMFC2实验2View)

// 特性
public:
	CMFC2实验2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC2实验2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC2实验2View.cpp 中的调试版本
inline CMFC2实验2Doc* CMFC2实验2View::GetDocument() const
   { return reinterpret_cast<CMFC2实验2Doc*>(m_pDocument); }
#endif

