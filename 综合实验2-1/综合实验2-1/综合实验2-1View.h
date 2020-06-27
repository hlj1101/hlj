
// 综合实验2-1View.h : C综合实验21View 类的接口
//

#pragma once

class C综合实验21Set;

class C综合实验21View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验21View();
	DECLARE_DYNCREATE(C综合实验21View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY21_FORM };
#endif
	C综合实验21Set* m_pSet;

// 特性
public:
	C综合实验21Doc* GetDocument() const;

// 操作
public:
	CString filename,path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C综合实验21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 综合实验2-1View.cpp 中的调试版本
inline C综合实验21Doc* C综合实验21View::GetDocument() const
   { return reinterpret_cast<C综合实验21Doc*>(m_pDocument); }
#endif

