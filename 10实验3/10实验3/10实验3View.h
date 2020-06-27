
// 10实验3View.h : CMy10实验3View 类的接口
//

#pragma once


class CMy10实验3View : public CView
{
protected: // 仅从序列化创建
	CMy10实验3View();
	DECLARE_DYNCREATE(CMy10实验3View)

// 特性
public:
	CMy10实验3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy10实验3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 10实验3View.cpp 中的调试版本
inline CMy10实验3Doc* CMy10实验3View::GetDocument() const
   { return reinterpret_cast<CMy10实验3Doc*>(m_pDocument); }
#endif

