
// MFC3课堂1.h: MFC3课堂1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC3课堂1App:
// 有关此类的实现，请参阅 MFC3课堂1.cpp
//

class CMFC3课堂1App : public CWinApp
{
public:
	CMFC3课堂1App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC3课堂1App theApp;
