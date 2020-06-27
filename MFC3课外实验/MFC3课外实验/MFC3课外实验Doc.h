
// MFC3课外实验Doc.h: CMFC3课外实验Doc 类的接口
//


#pragma once


class CMFC3课外实验Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC3课外实验Doc() noexcept;
	DECLARE_DYNCREATE(CMFC3课外实验Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC3课外实验Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CRect cr1, cr2, cr3,cr4;
	int ans = 0;
	int a, b;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
