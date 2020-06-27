
// 11实验12View.h : CMy11实验12View 类的接口
//

#pragma once

class CMy11实验12Set;

class CMy11实验12View : public CRecordView
{
protected: // 仅从序列化创建
	CMy11实验12View();
	DECLARE_DYNCREATE(CMy11实验12View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY1112_FORM };
#endif
	CMy11实验12Set* m_pSet;

// 特性
public:
	CMy11实验12Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMy11实验12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	long Number;
	CString name;
	long age;
	CString xingb;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 11实验12View.cpp 中的调试版本
inline CMy11实验12Doc* CMy11实验12View::GetDocument() const
   { return reinterpret_cast<CMy11实验12Doc*>(m_pDocument); }
#endif

