﻿
// MFC6实验1.h: MFC6实验1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC6实验1App:
// 有关此类的实现，请参阅 MFC6实验1.cpp
//

class CMFC6实验1App : public CWinApp
{
public:
	CMFC6实验1App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC6实验1App theApp;
