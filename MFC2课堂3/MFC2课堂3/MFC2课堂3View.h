﻿
// MFC2课堂3View.h: CMFC2课堂3View 类的接口
//

#pragma once


class CMFC2课堂3View : public CView
{
protected: // 仅从序列化创建
	CMFC2课堂3View() noexcept;
	DECLARE_DYNCREATE(CMFC2课堂3View)

// 特性
public:
	CMFC2课堂3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC2课堂3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC2课堂3View.cpp 中的调试版本
inline CMFC2课堂3Doc* CMFC2课堂3View::GetDocument() const
   { return reinterpret_cast<CMFC2课堂3Doc*>(m_pDocument); }
#endif

