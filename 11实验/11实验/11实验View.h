
// 11实验View.h : CMy11实验View 类的接口
//

#pragma once

class CMy11实验Set;

class CMy11实验View : public CRecordView
{
protected: // 仅从序列化创建
	CMy11实验View();
	DECLARE_DYNCREATE(CMy11实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY11_FORM };
#endif
	CMy11实验Set* m_pSet;

// 特性
public:
	CMy11实验Doc* GetDocument() const;

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
	virtual ~CMy11实验View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // 11实验View.cpp 中的调试版本
inline CMy11实验Doc* CMy11实验View::GetDocument() const
   { return reinterpret_cast<CMy11实验Doc*>(m_pDocument); }
#endif

