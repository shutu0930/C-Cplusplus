// DrawCircle.h : DrawCircle Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDrawCircleApp:
// �йش����ʵ�֣������ DrawCircle.cpp
//

class CDrawCircleApp : public CWinApp
{
public:
	CDrawCircleApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawCircleApp theApp;